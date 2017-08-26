#ifndef CONSOLE_MAIN_MENU_H
#define CONSOLE_MAIN_MENU_H

#include <memory>

#include <user_input_handler.h>

class ConsoleMainMenu {
 public:
  void RunMainMenu();

 private:
  void ProcessMenuUserInput();

  std::unique_ptr<UserInputHandler> user_input_handler_;
};

#endif  // CONSOLE_MAIN_MENU_H
