#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include <iostream>

#include <string>
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "primary_credit_operations.h"
#include "user_input.h"

using std::cout;
using std::cin;

class UserCredit {
  using string = std::string;

 public:

  bool AlreadyHasACredit(UserIdentifier &user_identifier) const;
  void RefuseToGrantAnotherCredit() const;

  bool SuggestACredit(UserIdentifier &user_identifier);

 private:
  bool ConsiderACreditBasedOnCash(UserIdentifier &user_identifier);
  bool GiveACredit(UserIdentifier &user_identifier);
  bool RefuseACredit(UserIdentifier &user_identifier);

  UserInput user_input_;
  CreditMessanger credit_messenger_;
  NoticeAboutError error_message;
  PrimaryCreditOperations primary_credit_operations_;
};

#endif  // USER_CREDIT_H
