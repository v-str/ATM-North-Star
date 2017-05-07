#ifndef REFILL_MESSENGER_H
#define REFILL_MESSENGER_H

#include <string>

class RefillMessenger {
 public:
  static const int kSecond = 1000;
  static const int kSleep = 100;
  static const int kFrame = 45;

  void ShowNotifyAboutCash() const;
  void ShowUserBalance(int balance) const;
  void WriteUserInfo(const std::string& info_title,
                     const std::string& value) const;
};

#endif  // REFILL_MESSENGER_H
