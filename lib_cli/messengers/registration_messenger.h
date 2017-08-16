#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

class RegistrationMessenger {
 public:
  static void ShowRegistrationLogo();
  static void ShowRegistrationReference();
  static void ShowIncorrectInput();
  static void ShowLoginTitle();
  static void ShowPasswordTitle();
  static void SuggestReenterRegistrationData();
  static void FarewellMessage();
  static void ClearScreen();
};

#endif  // REGISTRATION_MESSENGER_H
