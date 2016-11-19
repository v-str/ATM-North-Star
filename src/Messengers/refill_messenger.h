#ifndef REFILL_MESSENGER_H
#define REFILL_MESSENGER_H

#include <string>

#include "console_editor.h"

class RefillMessenger {
  using string = std::string;

 public:
  static const int kSecond = 1000;
  static const int kSleep = 100;
  static const int kFrame = 45;

  void ShowNotifyAboutCash() const;
  void ShowUserBalance(const int balance) const;
  void WriteUserInfo(const string &info_title, const string &value) const;

 private:
  ConsoleEditor console_editor_;
};

#endif  // REFILL_MESSENGER_H
