#ifndef NOTICE_MESSENGER_H
#define NOTICE_MESSENGER_H

#include "console_editor.h"

class NoticeMessenger {
 public:
  void ShowAcceptableMessageFrame() const;
  void ShowIncorrectLoginFrame() const;

  void ShowIncorrectFormatPassword() const;
  void ShowIncorrectData() const;
  void ShowIncorrectSum() const;
  void ShowUnacceptableWithdrawal(int amount_of_cash) const;
  void ShowError() const;
  void ShowSumCreditInfo() const;

 private:
  static const int kSecond = 1000;
  static const int kAccessFrame = 18;
  static const int kIncorrectDataFrame = 27;

  static const int kSleep = 100;
  static const int kFrame = 45;

  ConsoleEditor console_editor_;
};

#endif  // NOTICE_MESSENGER_H
