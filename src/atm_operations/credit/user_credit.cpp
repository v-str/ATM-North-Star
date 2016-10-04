#include "user_credit.h"

static const int kNull = 0;
static const int kMaxMultiplier = 15;
static const int kConsiderACredit = 1;
static const int kMinimalSumForCredit = 1000;
static const int kMaximalCredit = 0;
static const int kConsumerCredit = 1;

void UserCredit::StartCreditOperation(const UserIdentifier &user_identifier,
                                      CashOperator &cash_operator) {
  if (AlreadyHasACredit(cash_operator.GetCredit())) {
    RefuseToGrantAnotherCredit();
    credit_messenger_.ShowIncorrectCashInformation(cash_operator);
  } else {
    string user_login = user_identifier.GetLogin();
    SuggestACredit(cash_operator, user_login);
  }
}

bool UserCredit::AlreadyHasACredit(const int sum_of_credit) const {
  return sum_of_credit > kNull;
}

void UserCredit::RefuseToGrantAnotherCredit() const {
  credit_messenger_.RefusToGrantAnotherCredit();
}

void UserCredit::SuggestACredit(CashOperator &cash_operator,
                                const string &user_login) {
  credit_messenger_.ShowNotifyAboutCredit();
  if (user_input_.GetChoiceFromUser() == kConsiderACredit) {
    ConsiderACreditBasedOnCash(cash_operator, user_login);
  }
}

void UserCredit::ConsiderACreditBasedOnCash(CashOperator &cash_operator,
                                            const string &user_login) {
  if (cash_operator.IsCreditAvailable()) {
    GiveACredit(cash_operator, user_login);
  } else {
    int sum_of_cash = cash_operator.GetCash();
    RefuseACredit(sum_of_cash);
  }
}

void UserCredit::GiveACredit(CashOperator &cash_operator,
                             const string &user_login) {
  int user_cash_sum = cash_operator.GetCash();
  int maximal_sum_of_credit = kMaxMultiplier * user_cash_sum;

  credit_messenger_.ShowCreditConditions(maximal_sum_of_credit);

  int choice = user_input_.GetChoiceFromUser();
  if (choice == kMaxCredit) {
    credit_.GiveCreditByMode(cash_operator, user_login, maximal_sum_of_credit,
                             kMaximalCredit);
  } else if (choice == kUserCredit) {
    credit_.GiveCreditByMode(cash_operator, user_login, maximal_sum_of_credit,
                             kConsumerCredit);
  } else if (choice == kExit) {
    //    credit_messenger_.ShowExitMessage();
  } else {
    error_message.ShowIncorrectDataMessage();
  }
}

bool UserCredit::RefuseACredit(const int sum_of_cash) const {
  credit_messenger_.ShowRefuseACredit(sum_of_cash);
  return user_input_.SuggestUserToExit();
}
