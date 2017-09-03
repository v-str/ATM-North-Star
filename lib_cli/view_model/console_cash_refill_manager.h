#ifndef CONSOLE_CASH_REFILL_MANAGER_H
#define CONSOLE_CASH_REFILL_MANAGER_H

#include <user_input_handler.h>

class ConsoleCashRefillManager {
 public:
  void RunRefillMenu();

 private:
  enum SubMenuItems { kMainMenu = 1, kQuit };

  void ProcessUserInput();
  void ResetManipulationFlags();

  UserInputHandler user_input_handler_;

  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;
};

#endif  // CONSOLE_CASH_REFILL_MANAGER_H
