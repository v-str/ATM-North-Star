#ifndef CONFIRMATION_REGISTRATION_MESSENGER_H
#define CONFIRMATION_REGISTRATION_MESSENGER_H

#include <string>

class ConfirmationRegistrationMessenger {
 public:
  static void ShowConfirmationMessage(const std::string& login_string);

 private:
  static void WriteTitle();
  static void DrawConfirmationFrame();

  static void DrawHorizontalLine();
  static void DrawEmptyLine();

  static std::string kTitle;
  static std::string kGratingSymbol;

  static const int kLineLength = 41;
};

#endif  // CONFIRMATION_REGISTRATION_MESSENGER_H
