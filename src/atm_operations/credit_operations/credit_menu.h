#ifndef CREDIT_MENU_H
#define CREDIT_MENU_H

#include <iostream>
#include <string>

#include "atm_user.h"
#include "console_editor.h"
#include "credit.h"
#include "credit_messenger.h"
#include "user_input.h"

class CreditMenu {
  using string = std::string;

 public:
  void ShowCreditMenu(AtmUser* atm_user);

 private:
  enum SuggestVariantOfCredit { kMaxCreditSum = 1, kUserCreditSum };

  static const int kNull = 0;
  static const int kMaxMultiplier = 15;
  static const int kConsiderACredit = 1;
  static const int kMinimalCreditSum = 1000;
  static const int kMaximalCredit = 0;
  static const int kConsumerCredit = 1;

  static bool AlreadyHasACredit(int sum_of_credit);
  void RefuseACredit() const;
  void RefuseACredit(int sum_of_cash) const;

  void SuggestACredit(AtmUser* atm_user, const string& user_login) const;
  void ConsiderACreditBasedOnCash(AtmUser* atm_user,
                                  const string& user_login) const;
  void GiveACredit(AtmUser* atm_user, const string& user_login) const;

  Credit credit_;

  NoticeMessenger notice_messenger_;
  ConsoleEditor console_editor_;
  CreditMessenger credit_messenger_;
  UserInput user_input_;
};

#endif  // CREDIT_MENU_H
