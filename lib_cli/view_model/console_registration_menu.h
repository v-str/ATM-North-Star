#ifndef CONSOLE_REGISTRATION_MENU_H
#define CONSOLE_REGISTRATION_MENU_H

#include <memory>
#include <string>

#include <registration_reporter.h>

class UserInputHandler;

class ConsoleRegistrationMenu {
 public:
  ~ConsoleRegistrationMenu();

  void RunRegistrationMenu();
  void ReceiveRegistrationDataFromUser();

  template <typename T>
  void ShowLoginReport(const T& login_status);

  template <typename T>
  void ShowPasswordReport(const T& password_status);

  std::string LoginString() const;
  std::string PasswordString() const;

  bool IsUserWantToRegistrate() const;
  bool IsUserWantToExitProgram() const;

 private:
  enum MenuItems { kSymbolQuit, kRegistration, kInitialMenu, kDigitQuit };

  void ProcessMenuUserInput();

  void ResetManipulationFlags();

  void GetLoginStringFromUser();
  void GetPasswordStringFromUser();

  std::unique_ptr<UserInputHandler> input_handler_;

  RegistrationReporter reporter_;

  std::string login_;
  std::string password_;

  bool user_want_to_registrate_ = false;
  bool user_want_to_exit_ = false;
};

template <typename T>
void ConsoleRegistrationMenu::ShowPasswordReport(const T& password_status) {
  RegistrationReporter::RegistrationStatus status =
      static_cast<RegistrationReporter::RegistrationStatus>(password_status);

  reporter_.ShowPasswordReport(status);
}

template <typename T>
void ConsoleRegistrationMenu::ShowLoginReport(const T& login_status) {
  RegistrationReporter::RegistrationStatus status =
      static_cast<RegistrationReporter::RegistrationStatus>(login_status);

  reporter_.ShowLoginReport(status);
}

#endif  // CONSOLE_REGISTRATION_MENU_H
