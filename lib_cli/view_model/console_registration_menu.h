#ifndef CONSOLE_REGISTRATION_MENU_H
#define CONSOLE_REGISTRATION_MENU_H

#include <memory>

class UserInputHandler;

class ConsoleRegistrationMenu {
 public:
  ~ConsoleRegistrationMenu();

  void RunRegistrationMenu();

  bool UserWantToRegistrate() const;
  bool UserWantToExit() const;

 private:
  enum MenuItems { kSymbolQuit, kRegistration, kInitialMenu, kDigitQuit };

  void ProcessMenuUserInput();

  void ResetManipulationFlags();

  std::unique_ptr<UserInputHandler> input_handler_;

  bool user_want_to_registrate_ = false;
  bool user_want_to_exit_ = false;
};

#endif  // CONSOLE_REGISTRATION_MENU_H
