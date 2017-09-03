#ifndef CONSOLE_CASH_REFILL_MANAGER_H
#define CONSOLE_CASH_REFILL_MANAGER_H

#include <user_input_handler.h>

class ConsoleCashRefillManager {
 public:
  void RunRefillMenu();
  void ShowCashRefillingNotification();

  int SumOfCash() const;
  bool UserWantMainMenu() const;
  bool UserWantQuit() const;

 private:
  enum SubMenuItems { kMainMenu = 1, kQuit };

  void ProcessUserInput();
  bool IsUserInputContainSubMenu(int user_input);

  void ResetManipulationFlags();

  UserInputHandler user_input_handler_;

  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;

  int sum_of_cash_ = 0;

  static const int kNull = 0;
};

#endif  // CONSOLE_CASH_REFILL_MANAGER_H
