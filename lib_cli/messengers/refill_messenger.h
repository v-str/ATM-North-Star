#ifndef REFILL_MESSENGER_H
#define REFILL_MESSENGER_H

#include <string>

class RefillMessenger {
 public:
  void ShowNotifyAboutCash() const;
  void ShowUserBalance(int balance) const;

  static const int kSecond = 1000;
  static const int kSleep = 100;
  static const int kFrame = 45;
};

#endif  // REFILL_MESSENGER_H
