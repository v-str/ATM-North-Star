#ifndef CONSOLE_REGISTRATION_MENU_H
#define CONSOLE_REGISTRATION_MENU_H

#include <memory>
#include <string>

#include <registration_messenger.h>
#include <registration_reporter.h>

class UserInputHandler;

class ConsoleRegistrationMenu {
 public:
  ~ConsoleRegistrationMenu();

  void RunRegistrationMenu();
  void ReceiveRegistrationDataFromUser();

  void ConfirmRegistration();

  template <typename T>
  void ShowRegistratoinReport(const T& login_status, const T& password_status);

  std::string LoginString() const;
  std::string PasswordString() const;

  bool IsUserWantToRegistrate() const;
  bool IsUserWantToExitProgram() const;

 private:
  enum MenuItems { kSymbolQuit, kRegistration, kInitialMenu, kDigitQuit };

  void ShowLoginReport(const RegistrationReporter::RegistrationStatus login);
  void ShowPasswordReport(
      const RegistrationReporter::RegistrationStatus password);

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
void ConsoleRegistrationMenu::ShowRegistratoinReport(const T& login_status,
                                                     const T& password_status) {
  RegistrationMessenger::ClearScreen();

  RegistrationReporter::RegistrationStatus login =
      static_cast<RegistrationReporter::RegistrationStatus>(login_status);

  RegistrationReporter::RegistrationStatus password =
      static_cast<RegistrationReporter::RegistrationStatus>(password_status);

  ShowLoginReport(login);
  ShowPasswordReport(password);
}

#endif  // CONSOLE_REGISTRATION_MENU_H
