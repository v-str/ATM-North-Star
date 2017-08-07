#ifndef WITHDRAWAL_MESSENGER_H
#define WITHDRAWAL_MESSENGER_H

class WithdrawalMessenger {
 public:
  static void ShowSumOfWithdrawal(int sum_of_cash);
  static void ShowPasswordString();
  static void ShowIncorrectPasswordMessage();
  static void EnterSumOfWithdrawal();
  static void ShowSuccessfulWithdrawal(int sum_of_cash, int sum_of_withdrawal);
};

#endif  // WITHDRAWAL_MESSENGER_H
