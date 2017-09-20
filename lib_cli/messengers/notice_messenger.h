#ifndef NOTICE_MESSENGER_H
#define NOTICE_MESSENGER_H

class NoticeMessenger {
 public:
  static void ShowAcceptableMessageFrame();
  static void ShowIncorrectLoginFrame();

  static void ShowIncorrectFormatPassword();
  static void ShowIncorrectSum();
  static void ShowUnacceptableWithdrawal(int amount_of_cash);
  static void ShowError();
  static void ShowSumCreditInfo();

 private:
  static const int kSecond = 1000;
  static const int kAccessFrame = 18;
  static const int kIncorrectDataFrame = 27;

  static const int kSleep = 100;
  static const int kFrame = 45;
};

#endif  // NOTICE_MESSENGER_H
