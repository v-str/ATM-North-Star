#ifndef CONSOLE_REGISTRATION_MENU_H
#define CONSOLE_REGISTRATION_MENU_H

#include <memory>

class UserInputHandler;

class ConsoleRegistrationMenu {
 public:
  ConsoleRegistrationMenu();
  ~ConsoleRegistrationMenu();

  void RunRegistrationMenu();

 private:
  std::unique_ptr<UserInputHandler> user_input_;
  std::unique_ptr<UserInputHandler> menu_input_;
};

#endif  // CONSOLE_REGISTRATION_MENU_H
