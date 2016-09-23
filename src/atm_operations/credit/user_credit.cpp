#include "user_credit.h"

const int kint_null = 0;
const int kmax_multiplier = 15;
const int kconsider_a_credit = 1;
const int kMinimalSumForCredit = 1000;

bool UserCredit::StartCreditOperation(UserIdentifier &user_identifier,
                                      CashOperator &cash_operator,
                                      UserMessenger &user_messenger) {
  if (AlreadyHasACredit(cash_operator)) {
    RefuseToGrantAnotherCredit();
    user_messenger.ShowAccountInformation(user_identifier, cash_operator);
    return user_input_.SuggestUserToExit();
  } else {
    string user_login = user_identifier.GetLogin();
    return SuggestACredit(cash_operator, user_login);
  }
}

bool UserCredit::AlreadyHasACredit(const CashOperator &cash_operator) const {
  return cash_operator.GetCredit() > kint_null;
}

void UserCredit::RefuseToGrantAnotherCredit() const {
  credit_messenger_.RefusToGrantAnotherCredit();
}

bool UserCredit::SuggestACredit(CashOperator &cash_operator,
                                const string &user_login) {
  credit_messenger_.ShowNotifyAboutCredit();
  if (user_input_.GetChoiceFromUser() == kconsider_a_credit) {
    return ConsiderACreditBasedOnCash(cash_operator, user_login);
  }
  return false;
}

bool UserCredit::ConsiderACreditBasedOnCash(CashOperator &cash_operator,
                                            const string &user_login) {
  if (cash_operator.IsCreditAvailable()) {
    return GiveACredit(cash_operator, user_login);
  } else {
    return RefuseACredit(cash_operator);
  }
}

bool UserCredit::GiveACredit(CashOperator &cash_operator,
                             const string &user_login) {
  int maximal_sum_of_credit = kmax_multiplier * cash_operator.GetCash();
  credit_messenger_.ShowCreditConditions(maximal_sum_of_credit);
  int choice = user_input_.GetChoiceFromUser();
  if (choice == kMaxCredit) {
    return primary_credit_operations_.MaxCreditCalculation(
        cash_operator, user_login, maximal_sum_of_credit);
  } else if (choice == kUserCredit) {
    return primary_credit_operations_.IndividualCreditCalculation(
        cash_operator, user_login, maximal_sum_of_credit);
  } else if (choice == kMainMenu) {
    return false;
  } else if (choice == kExit) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_message.ShowIncorrectDataMessage();
  }
}

bool UserCredit::RefuseACredit(const CashOperator &cash_operator) const {
  credit_messenger_.ShowRefuseACredit(cash_operator.GetCash());
  return user_input_.SuggestUserToExit();
}
