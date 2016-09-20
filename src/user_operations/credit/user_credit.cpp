#include "user_credit.h"

static const int kMinimalSumForCredit = 1000;

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
  return cash_operator.GetCredit() > 0;
}

void UserCredit::RefuseToGrantAnotherCredit() const {
  messenger_.RefusToGrantAnotherCredit();
}

bool UserCredit::SuggestACredit(CashOperator &cash_operator,
                                const string &user_login) {
  messenger_.ShowNotifyAboutCredit();
  if (user_input_.GetChoiceFromUser() == 1) {
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
  int maximal_sum_of_credit = 15 * cash_operator.GetCash();
  messenger_.ShowCreditConditions(maximal_sum_of_credit);
  int choice = user_input_.GetChoiceFromUser();
  if (choice == 1) {
    return primary_credit_operations_.MaxCreditCalculation(
        cash_operator, user_login, maximal_sum_of_credit);
  } else if (choice == 2) {
    return primary_credit_operations_.IndividualCreditCalculation(
        cash_operator, user_login, maximal_sum_of_credit);
  } else if (choice == 3) {
    return false;
  } else if (choice == 4) {
    return messenger_.ShowExitMessage();
  } else {
    return error_message.ShowIncorrectDataMessage();
  }
}

bool UserCredit::RefuseACredit(const CashOperator &cash_operator) const {
  messenger_.ShowRefuseACredit(cash_operator.GetCash());

  return user_input_.SuggestUserToExit();
}
