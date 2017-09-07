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
  static const int kSecond = 1000;
};

#endif  // WITHDRAWAL_MESSENGER_H
