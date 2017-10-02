#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

class RegistrationMessenger {
 public:
  static void ShowRegistrationLogo();
  static void ShowRegistrationReference();
  static void ShowIncorrectMenuInput();
  static void ShowLoginTitle();
  static void ShowPasswordTitle();
  static void IncorrectRegistrationNotification();
  static void ShowConfirmationMessage();
  static void FarewellMessage();
  static void ClearScreen();

 private:
  static const int kTitleDelay = 15;
};

#endif  // REGISTRATION_MESSENGER_H
