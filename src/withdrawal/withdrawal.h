#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>
#include <string>

#include "cash_operator.h"
#include "user_identifier.h"
#include "user_messenger.h"

using std::cout;
using std::cin;

class Withdrawal {
  using string = std::string;

 public:
  int SumOfWithdrawal() const;
  bool IsWithdrawalAcceptable(const CashOperator &cash_operator,
                              double cash_sum) const;
  bool IsCorrectPasswordAtWithdrawal(const string &password,
                                     UserIdentifier &user_identifier) const;

  void WithdrawFromAccount(CashOperator &cash_operator, int sum_of_withdrawal);

 private:
  UserMessenger user_messanger_;
};

#endif  // WITHDRAWAL_H
