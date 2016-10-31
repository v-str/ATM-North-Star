#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>
#include <string>

#include "notifier.h"
#include "user_input.h"
#include "withdrawal_messenger.h"
#include "cash_operator.h"
#include "user_identifier.h"

class Withdrawal {
  using string = std::string;

 public:
  void WithdrawCashFromUser(CashOperator &cash_operator,
                            UserIdentifier &user_identifier);

  int SumOfWithdrawal() const;
  bool IsWithdrawalAcceptable(const CashOperator &cash_operator,
                              double cash_sum) const;
  bool IsCorrectPasswordAtWithdrawal(const string &password,
                                     UserIdentifier &user_identifier) const;

  void WithdrawFromAccount(CashOperator &cash_operator, int sum_of_withdrawal);

 private:
  static const int kNull = 0;

  UserInput user_input_;
  Notifier error_message_;
  WithdrawalMessenger messenger_;
  SystemUtility utility_;
};

#endif  // WITHDRAWAL_H
