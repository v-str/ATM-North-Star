#ifndef WITHDRAWAL_MESSENGER_H
#define WITHDRAWAL_MESSENGER_H

class WithdrawalMessenger {
 public:
  static void ShowWithdrawalNotification();
  static void ShowPasswordString();
  static void ShowIncorrectPasswordMessage();
  static void EnterSumOfWithdrawal();
  static void ShowSuccessfulWithdrawal(int sum_of_cash, int sum_of_withdrawal);
  static void ShowIncorrectInputMessage();

 private:
  static const int kStripLength = 45;
};

#endif  // WITHDRAWAL_MESSENGER_H
