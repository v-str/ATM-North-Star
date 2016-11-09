#include "user_credit.h"

void UserCredit::StartCreditOperation(const UserIdentifier &user_identifier,
                                      CashOperator &cash_operator) {
  utility_.ClearScreen();
  if (AlreadyHasACredit(cash_operator.GetCredit())) {
    RefuseToGrantAnotherCredit();
    credit_messenger_.ShowIncorrectCashInformation(cash_operator.GetCash());
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
  if (user_input_.GetValueFromUser() == kConsiderACredit) {
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

  int choice = user_input_.GetValueFromUser();
  if (choice == kMaxCredit) {
    credit_.GiveCreditByMode(cash_operator, user_login, maximal_sum_of_credit,
                             kMaximalCredit);
  } else if (choice == kUserCredit) {
    credit_.GiveCreditByMode(cash_operator, user_login, maximal_sum_of_credit,
                             kConsumerCredit);
  } else if (choice == kExit) {
  } else {
    notice_messenger_.ShowError();
  }
}

bool UserCredit::RefuseACredit(const int sum_of_cash) const {
  credit_messenger_.ShowRefuseACredit(sum_of_cash);
  return user_input_.SuggestUserToExit();
}
