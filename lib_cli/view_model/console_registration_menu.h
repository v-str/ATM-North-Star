#ifndef CONSOLE_REGISTRATION_MENU_H
#define CONSOLE_REGISTRATION_MENU_H

#include <memory>
#include <string>

class UserInputHandler;

class ConsoleRegistrationMenu {
 public:
  ~ConsoleRegistrationMenu();

  void RunRegistrationMenu();
  void ReceiveRegistrationDataFromUser();
  void ShowRegistrationReport();

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

  bool user_want_to_registrate_ = false;
  bool user_want_to_exit_ = false;

  std::string login_;
  std::string password_;
};

#endif  // CONSOLE_REGISTRATION_MENU_H
