#ifndef NOTICE_MESSENGER_H
#define NOTICE_MESSENGER_H

class NoticeMessenger {
 public:
  void ShowAcceptableMessageFrame() const;
  void ShowIncorrectLoginFrame() const;

  void ShowIncorrectFormatPassword() const;
  void ShowIncorrectSum() const;
  void ShowUnacceptableWithdrawal(int amount_of_cash) const;
  void ShowError() const;
  void ShowSumCreditInfo() const;

 private:
  static constexpr int kSecond = 1000;
  static constexpr int kAccessFrame = 18;
  static constexpr int kIncorrectDataFrame = 27;

  static constexpr int kSleep = 100;
  static constexpr int kFrame = 45;
};

#endif  // NOTICE_MESSENGER_H
