#include "user_credit.h"

void UserCredit::StartCreditOperation(AtmUser &atm_user) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  if (AlreadyHasACredit(atm_user.GetCredit())) {
    RefuseToGrantAnotherCredit();
    credit_messenger_.ShowIncorrectCashInformation(atm_user.GetCash());
  } else {
    string user_login = atm_user.GetLogin();
    SuggestACredit(atm_user, user_login);
  }
}

bool UserCredit::AlreadyHasACredit(const int sum_of_credit) {
  return sum_of_credit > kNull;
}

void UserCredit::RefuseToGrantAnotherCredit() const {
  credit_messenger_.RefuseToGrantAnotherCredit();
}

void UserCredit::SuggestACredit(AtmUser &atm_user,
                                const string &user_login) const {
  credit_messenger_.ShowNotifyAboutCredit();
  if (user_input_.GetValueFromUser() == kConsiderACredit) {
    ConsiderACreditBasedOnCash(atm_user, user_login);
  }
}

void UserCredit::ConsiderACreditBasedOnCash(AtmUser &atm_user,
                                            const string &user_login) const {
  if (atm_user.IsCreditAvailable()) {
    GiveACredit(atm_user, user_login);
  } else {
    int sum_of_cash = atm_user.GetCash();
    RefuseACredit(sum_of_cash);
  }
}

void UserCredit::GiveACredit(AtmUser &atm_user,
                             const string &user_login) const {
  int user_cash_sum = atm_user.GetCash();
  int maximal_sum_of_credit = kMaxMultiplier * user_cash_sum;

  console_editor_.AddEmptyLineNTimes(1);
  credit_messenger_.ShowCreditConditions(maximal_sum_of_credit);

  int choice = user_input_.GetValueFromUser();
  if (choice == kMaxCredit) {
    credit_.GiveCreditByMode(atm_user, user_login, maximal_sum_of_credit,
                             kMaximalCredit);
  } else if (choice == kUserCredit) {
    credit_.GiveCreditByMode(atm_user, user_login, maximal_sum_of_credit,
                             kConsumerCredit);

  } else {
    notice_messenger_.ShowError();
  }
}

void UserCredit::RefuseACredit(const int sum_of_cash) const {
  console_editor_.AddEmptyLineNTimes(1);
  credit_messenger_.ShowRefuseACredit(sum_of_cash);
}
