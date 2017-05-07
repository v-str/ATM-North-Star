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
  static constexpr int kSecond = 1000;
  static constexpr int kAccessFrame = 18;
  static constexpr int kIncorrectDataFrame = 27;

  static constexpr int kSleep = 100;
  static constexpr int kFrame = 45;
};

#endif  // NOTICE_MESSENGER_H
