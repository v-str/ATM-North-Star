#ifndef CONSOLE_WITHDRAWAL_MENU_H
#define CONSOLE_WITHDRAWAL_MENU_H

#include <string>

class ConsoleWithdrawalMenu {
 public:
  void RunWithdrawalMenu();

  std::string GetPasswordFromUser() const;
  int SumOfWithdrawal() const;
  bool UserWantMainMenu() const;
  bool UserWantQuit() const;
  void ShowSuccessfulWithdrawal() const;
  void ShowIncorrectWithdrawal() const;

 private:
  enum SubMenuItems { kNull, kMainMenu, kQuit };

  void ProcessUserInput();
  void CheckUserInput(int user_input);
  void ResetManipulationFlags();

  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;
  int sum_of_withdrawal_ = 0;
};

#endif  // CONSOLE_WITHDRAWAL_MENU_H
