#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>

#include "cash_operator.h"
#include "user_identifier.h"
#include "user_messenger.h"

using std::cout;
using std::cin;

class Withdrawal {
 public:
  int SumOfWithdrawal() const;
  bool IsWithdrawalAcceptable(const CashOperator &cash_operator,
                              double cash_sum) const;
private:
  UserMessenger user_messanger_;
};

#endif  // WITHDRAWAL_H
