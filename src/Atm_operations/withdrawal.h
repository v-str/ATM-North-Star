#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>
#include <string>

#include "cash_operator.h"
#include "user_identifier.h"
#include "user_input.h"
#include "withdrawal_messenger.h"

#include "notice_messenger.h"

class Withdrawal {
  using string = std::string;

 public:
  void WithdrawCashFromUser(CashOperator &cash_operator,
                            UserIdentifier &user_identifier);

  int GetSumOfWithdrawal() const;
  bool IsWithdrawalAcceptable(const CashOperator &cash_operator,
                              double cash_sum) const;
  bool IsCorrectPasswordAtWithdrawal(const string &password,
                                     UserIdentifier &user_identifier) const;

  void WithdrawFromAccount(CashOperator &cash_operator, int sum_of_withdrawal);

 private:
  static const int kNull = 0;

  UserInput user_input_;
  WithdrawalMessenger messenger_;
  SystemUtility utility_;

  NoticeMessenger notice_messenger_;
};

#endif  // WITHDRAWAL_H
