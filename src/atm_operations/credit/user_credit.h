#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include <iostream>

#include <string>
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "credit.h"
#include "user_identifier.h"
#include "user_input.h"
#include "user_messenger.h"

using std::cout;
using std::cin;

class UserCredit {
  using string = std::string;
  enum SuggestVariantOfCredit { kMaxCredit = 1, kUserCredit, kMainMenu, kExit };

 public:
  bool StartCreditOperation(UserIdentifier &user_identifier,
                            CashOperator &cash_operator,
                            UserMessenger &user_messenger);

 private:
  bool AlreadyHasACredit(const int sum_of_credit) const;
  void RefuseToGrantAnotherCredit() const;

  bool SuggestACredit(CashOperator &cash_operator, const string &user_login);
  bool ConsiderACreditBasedOnCash(CashOperator &cash_operator,
                                  const string &user_login);
  bool GiveACredit(CashOperator &cash_operator, const string &user_login);
  bool RefuseACredit(const int sum_of_cash) const;

  UserInput user_input_;
  CreditMessanger credit_messenger_;
  NoticeAboutError error_message;
  Credit credit_;
};

#endif  // USER_CREDIT_H
