#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include <iostream>
#include <string>

#include "credit.h"
#include "credit_messenger.h"
#include "user_identifier.h"
#include "user_input.h"

class UserCredit {
  using string = std::string;

 public:
  void StartCreditOperation(const UserIdentifier &user_identifier,
                            CashOperator &cash_operator);

 private:
  enum SuggestVariantOfCredit { kMaxCredit = 1, kUserCredit, kExit };

  static const int kNull = 0;
  static const int kMaxMultiplier = 15;
  static const int kConsiderACredit = 1;
  static const int kMinimalSumForCredit = 1000;
  static const int kMaximalCredit = 0;
  static const int kConsumerCredit = 1;

  bool AlreadyHasACredit(const int sum_of_credit) const;
  void RefuseToGrantAnotherCredit() const;
  bool RefuseACredit(const int sum_of_cash) const;

  void SuggestACredit(CashOperator &cash_operator, const string &user_login);
  void ConsiderACreditBasedOnCash(CashOperator &cash_operator,
                                  const string &user_login);
  void GiveACredit(CashOperator &cash_operator, const string &user_login);

  UserInput user_input_;
  CreditMessanger credit_messenger_;
  Credit credit_;
  SystemUtility utility_;
  NoticeMessenger notice_messenger_;
};

#endif  // USER_CREDIT_H
