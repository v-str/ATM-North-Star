#ifndef WITHDRAWAL_MESSENGER_H
#define WITHDRAWAL_MESSENGER_H

#include "system_utility.h"

class WithdrawalMessenger {
 public:
  void ShowSumOfWithdrawal(int sum_of_cash) const;
  void ShowPasswordString() const;
  void ShowIncorrectPasswordMessage() const;
  void EnterSumOfWithdrawal() const;

  void ShowSuccessfulWithdrawal(int sum_of_cash, int sum_of_withdrawal);

 private:
  SystemUtility utility_;
};

#endif  // WITHDRAWAL_MESSENGER_H
