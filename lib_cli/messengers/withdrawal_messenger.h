#ifndef WITHDRAWAL_MESSENGER_H
#define WITHDRAWAL_MESSENGER_H

class WithdrawalMessenger {
 public:
  static void ShowWithdrawalNotification();
  static void RequirePasswordMessage();
  static void EnterSumOfWithdrawal();
  static void ShowSuccessfulWithdrawal();
  static void IncorrectWithdrawalMessage();

 private:
  static const int kStripLength = 45;
};

#endif  // WITHDRAWAL_MESSENGER_H
