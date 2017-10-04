#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

class RegistrationMessenger {
 public:
  static void ShowRegistrationLogo();
  static void ShowRegistrationReference();
  static void ShowControlQuestionNotification();
  static void ShowLoginTitle();
  static void ShowPasswordTitle();
  static void ShowPasswordTooltipTitle();
  static void IncorrectRegistrationNotification();
  static void ShowConfirmationMessage();

 private:
  static const int kTitleDelay = 15;
};

#endif  // REGISTRATION_MESSENGER_H
