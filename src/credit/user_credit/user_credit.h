#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include <iostream>

#include <string>
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "primary_credit_operations.h"
#include "user_identifier.h"
#include "user_input.h"
#include "user_messenger.h"

using std::cout;
using std::cin;

class UserCredit {
  using string = std::string;

 public:
  bool StartCreditOperation(UserIdentifier &user_identifier,
                            CashOperator &cash_operator,
                            UserMessenger &user_messenger);

  bool AlreadyHasACredit(const CashOperator &cash_operator) const;
  void RefuseToGrantAnotherCredit() const;

  bool SuggestACredit(CashOperator &cash_operator, const string &user_login);

 private:
  bool ConsiderACreditBasedOnCash(CashOperator &cash_operator,
                                  const string &user_login);
  bool GiveACredit(CashOperator &cash_operator, const string &user_login);
  bool RefuseACredit(const CashOperator &cash_operator) const;

  UserInput user_input_;
  CreditMessanger messenger_;
  NoticeAboutError error_message;
  PrimaryCreditOperations primary_credit_operations_;
};

#endif  // USER_CREDIT_H
