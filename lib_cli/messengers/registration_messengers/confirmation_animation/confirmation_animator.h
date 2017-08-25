#ifndef CONFIRMATION_ANIMATOR_H
#define CONFIRMATION_ANIMATOR_H

#include <string>

class ConfirmationAnimator {
 public:
  static void ShowConfirmationMessage(const std::string& login_string);

 private:
  static void DrawConfirmationFrame();
  static void UpdateFrame(int loading_percent);

  static std::string kFrameSymbol;

  static const int kSleepDelay = 100;
};

#endif  // CONFIRMATION_ANIMATOR_H
