#ifndef CONSOLE_REGISTRATION_MENU_H
#define CONSOLE_REGISTRATION_MENU_H

#include <memory>
#include <string>
#include <vector>

#include <registration_reporter.h>
#include <registration_status.h>
#include <user_input_handler.h>

class ConsoleRegistrationMenu {
 public:
  void RunRegistrationMenu();
  void ReceiveRegistrationDataFromUser();
  void RunRegistrationConfirmation();
  void RunIncorrectRegistrationNotification();

  void ShowConfirmationAnimation(
      const std::string& login_string,
      const std::vector<std::string>& processes_report) const;

  template <typename T>
  void ShowRegistratoinReport(const T& login_status,
                              const T& password_status) const;

  std::string LoginString() const;
  std::string PasswordString() const;

  bool IsUserWantToRegistrate() const;
  bool IsUserWantToRepeatRegistrate() const;
  bool IsUserWantToExitProgram() const;
  bool IsUserWantToInitialMenu() const;
  bool IsRegistrationConfirmed() const;

 private:
  enum MenuItems { kAction = 1, kInitialMenu, kQuit };

  void ShowLoginReport(const CONSOLE::RegistrationStatus login_status) const;
  void ShowPasswordReport(
      const CONSOLE::RegistrationStatus password_status) const;

  void ProcessUserInput(bool& action);
  void ResetManipulationFlags();
  void GetLoginStringFromUser();
  void GetPasswordStringFromUser();
  void GetPasswordTooltipFromUser();

  UserInputHandler input_handler_;
  RegistrationReporter reporter_;

  std::string login_;
  std::string password_;
  std::string password_tooltip_;

  bool user_want_to_registrate_ = false;
  bool user_want_to_repeat_registration_ = false;
  bool user_want_to_quit_ = false;
  bool user_want_to_initial_menu_ = false;
  bool registration_confirmed_ = false;
};

template <typename T>
void ConsoleRegistrationMenu::ShowRegistratoinReport(
    const T& login_status, const T& password_status) const {
  ShowLoginReport(static_cast<CONSOLE::RegistrationStatus>(login_status));
  ShowPasswordReport(static_cast<CONSOLE::RegistrationStatus>(password_status));
}

#endif  // CONSOLE_REGISTRATION_MENU_H
