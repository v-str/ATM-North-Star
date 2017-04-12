#include "credit_menu.h"

void CreditMenu::ShowCreditMenuFor(AtmUser* atm_user) {
  if (AlreadyHasACredit(atm_user->GetCredit())) {
    // RefuseACredit();
    // credit_messenger_.ShowIncorrectCashInformation(atm_user->GetCash());
  } else {
    string user_login = atm_user->GetLogin();
    SuggestACredit(atm_user, user_login);
  }
}

bool CreditMenu::AlreadyHasACredit(int sum_of_credit) {
  return sum_of_credit > kNull;
}

void CreditMenu::RefuseACredit() const {
  credit_messenger_.RefuseACreditBasedOnAnotherCredit();
}

void CreditMenu::SuggestACredit(AtmUser* atm_user,
                                const string& user_login) const {
  credit_messenger_.NotifyAboutCredit();
  if (user_input_.GetValueFromUser() == kConsiderACredit) {
    ConsiderACreditBasedOnCash(atm_user, user_login);
  }
}

void CreditMenu::ConsiderACreditBasedOnCash(AtmUser* atm_user,
                                            const string& user_login) const {
  if (atm_user->IsCreditAvailable()) {
    GiveACredit(atm_user, user_login);
  } else {
    // int sum_of_cash = atm_user->GetCash();
    // RefuseACredit(sum_of_cash);
  }
}

void CreditMenu::GiveACredit(AtmUser* atm_user,
                             const string& user_login) const {
  int user_cash_sum = atm_user->GetCash();
  int maximal_sum_of_credit = kMaxMultiplier * user_cash_sum;

  console_editor_.AddEmptyLineNTimes(1);
  credit_messenger_.ShowCreditConditions(maximal_sum_of_credit);

  int choice = user_input_.GetValueFromUser();
  if (choice == kMaxCreditSum) {
    credit_.GiveCredit(atm_user, user_login, maximal_sum_of_credit,
                       kMaximalCredit);
  } else if (choice == kUserCreditSum) {
    credit_.GiveCredit(atm_user, user_login, maximal_sum_of_credit,
                       kConsumerCredit);
  }
}

void CreditMenu::RefuseACredit(int sum_of_cash) const {
  console_editor_.AddEmptyLineNTimes(1);
  credit_messenger_.RefuseACreditBasedOnCash(sum_of_cash);
}
