#ifndef CONSOLE_MAIN_MENU_H
#define CONSOLE_MAIN_MENU_H

#include <memory>

#include <user_input.h>

class ConsoleMainMenu {
 public:
  void RunMainMenu();

 private:
  std::unique_ptr<UserInput> user_input_;
};

#endif  // CONSOLE_MAIN_MENU_H
