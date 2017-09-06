#ifndef REFILL_MESSENGER_H
#define REFILL_MESSENGER_H

#include <string>

class RefillMessenger {
 public:
  static void ShowRefillNotification();
  static void ShowSuccessfulCashRefilling();
  static void ShowIncorrectRefillingNotification();
  static void ShowIncorrectInputMessage();

  static const int kSecond = 1000;
  static const int kSleep = 100;
  static const int kStripLength = 45;
};

#endif  // REFILL_MESSENGER_H
