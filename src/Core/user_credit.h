#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include "atm_user.h"
#include "console_editor.h"
#include "credit.h"
#include "credit_messenger.h"
#include "user_input.h"

#include <iostream>
#include <string>

class UserCredit {
  using string = std::string;

 public:
  void StartCreditOperation(AtmUser &atm_user);

 private:
  enum SuggestVariantOfCredit { kMaxCredit = 1, kUserCredit };

  static const int kNull = 0;
  static const int kMaxMultiplier = 15;
  static const int kConsiderACredit = 1;
  static const int kMinimalSumForCredit = 1000;
  static const int kMaximalCredit = 0;
  static const int kConsumerCredit = 1;

  static bool AlreadyHasACredit(int sum_of_credit);
  void RefuseToGrantAnotherCredit() const;
  void RefuseACredit(int sum_of_cash) const;

  void SuggestACredit(AtmUser &atm_user, const string &user_login) const;
  void ConsiderACreditBasedOnCash(AtmUser &atm_user,
                                  const string &user_login) const;
  void GiveACredit(AtmUser &atm_user, const string &user_login) const;

  UserInput user_input_;
  CreditMessanger credit_messenger_;
  Credit credit_;
  NoticeMessenger notice_messenger_;
  ConsoleEditor console_editor_;
};

#endif  // USER_CREDIT_H
