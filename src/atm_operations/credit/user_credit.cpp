#include "user_credit.h"

static const int kNull = 0;
static const int kMaxMultiplier = 15;
static const int kConsiderACredit = 1;
static const int kMinimalSumForCredit = 1000;
static const int kMaximalCredit = 0;
static const int kConsumerCredit = 1;

bool UserCredit::StartCreditOperation(UserIdentifier &user_identifier,
                                      CashOperator &cash_operator,
                                      UserMessenger &user_messenger) {
  if (AlreadyHasACredit(cash_operator.GetCredit())) {
    RefuseToGrantAnotherCredit();
    user_messenger.ShowAccountInformation(user_identifier, cash_operator);
    return user_input_.SuggestUserToExit();
  } else {
    string user_login = user_identifier.GetLogin();
    return SuggestACredit(cash_operator, user_login);
  }
}

bool UserCredit::AlreadyHasACredit(const int sum_of_credit) const {
  return sum_of_credit > kNull;
}

void UserCredit::RefuseToGrantAnotherCredit() const {
  credit_messenger_.RefusToGrantAnotherCredit();
}

bool UserCredit::SuggestACredit(CashOperator &cash_operator,
                                const string &user_login) {
  credit_messenger_.ShowNotifyAboutCredit();
  if (user_input_.GetChoiceFromUser() == kConsiderACredit) {
    return ConsiderACreditBasedOnCash(cash_operator, user_login);
  }
  return false;
}

bool UserCredit::ConsiderACreditBasedOnCash(CashOperator &cash_operator,
                                            const string &user_login) {
  if (cash_operator.IsCreditAvailable()) {
    return GiveACredit(cash_operator, user_login);
  } else {
    int sum_of_cash = cash_operator.GetCash();
    return RefuseACredit(sum_of_cash);
  }
}

bool UserCredit::GiveACredit(CashOperator &cash_operator,
                             const string &user_login) {
  int user_cash_sum = cash_operator.GetCash();
  int maximal_sum_of_credit = kMaxMultiplier * user_cash_sum;

  credit_messenger_.ShowCreditConditions(maximal_sum_of_credit);

  int choice = user_input_.GetChoiceFromUser();
  if (choice == kMaxCredit) {
    return primary_credit_operations_.GetCreditData(
        cash_operator, user_login, maximal_sum_of_credit, kMaximalCredit);
  } else if (choice == kUserCredit) {
    return primary_credit_operations_.GetCreditData(
        cash_operator, user_login, maximal_sum_of_credit, kConsumerCredit);
  } else if (choice == kMainMenu) {
    return false;
  } else if (choice == kExit) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_message.ShowIncorrectDataMessage();
  }
}

bool UserCredit::RefuseACredit(const int sum_of_cash) const {
  credit_messenger_.ShowRefuseACredit(sum_of_cash);
  return user_input_.SuggestUserToExit();
}
