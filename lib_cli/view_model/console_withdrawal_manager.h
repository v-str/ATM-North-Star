#ifndef CONSOLE_WITHDRAWAL_MANAGER_H
#define CONSOLE_WITHDRAWAL_MANAGER_H

#include <user_input_handler.h>

class ConsoleWithdrawalManager {
 public:
  void ShowWithdrawNotification();

 private:
  enum SubMenuItems { kNull, kMainMenu, kQuit };

  void ProcessUserInput();

  bool IsUserInputCorrect(int user_input);

  void ResetManipulationFlags();

  UserInputHandler user_input_handler_;

  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;

  int sum_of_withdrawal_ = 0;
};

#endif  // CONSOLE_WITHDRAWAL_MANAGER_H
