#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

class AtmUser;

class Withdrawal {
 public:
  static void WithdrawCashFrom(AtmUser* user, int sum_of_withdrawal);
};

#endif  // WITHDRAWAL_H
