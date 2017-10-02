#ifndef REFILL_MESSENGER_H
#define REFILL_MESSENGER_H

#include <string>

class RefillMessenger {
 public:
  static void ShowRefillNotification();
  static void ShowSuccessfulCashRefilling();
  static void ShowIncorrectRefillingMessage();
  static void ShowMainMenuQuit();

  static const int kSecond = 200;
  static const int kStripLength = 45;
};

#endif  // REFILL_MESSENGER_H
