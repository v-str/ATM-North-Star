#ifndef CONFIRMATION_ANIMATOR_H
#define CONFIRMATION_ANIMATOR_H

#include <string>

class ConfirmationAnimator {
 public:
  static void ShowConfirmationMessage(const std::string& login_string);

 private:
  static void DrawConfirmationFrame();

  static void DrawHorizontalLine();
  static void DrawEmptyLine();
  static void DrawConfirmationTextLine();
  static void DrawLoginStringLine();

  static std::string kTitle;
  static std::string kGratingSymbol;
  static std::string kSpaceSymbol;
  static std::string kConfirmationText;
  static std::string kLoginString;

  static const int kLineLength = 41;
};

#endif  // CONFIRMATION_ANIMATOR_H
