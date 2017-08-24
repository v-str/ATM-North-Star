#ifndef CONFIRMATION_ANIMATOR_H
#define CONFIRMATION_ANIMATOR_H

#include <string>

class ConfirmationAnimator {
 public:
  static void ShowConfirmationMessage(const std::string& login_string);

 private:
  static void DrawConfirmationFrame();
};

#endif  // CONFIRMATION_ANIMATOR_H
