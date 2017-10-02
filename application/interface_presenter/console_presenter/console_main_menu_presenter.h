#ifndef CONSOLE_MAIN_MENU_PRESENTER_H
#define CONSOLE_MAIN_MENU_PRESENTER_H

#include <console_main_menu.h>

class ConsoleMainMenuPresenter {
 public:
  void RunMainMenu();

  bool UserWantQuit() const;

 private:
  void PerformMenuItem();
  void RunAccountMenu();
  void RunRefillMenu();
  void RunCreditCalculator();
  void RunWithdrawalPresenter();
  void RunStatementMenu();

  void ResetManipulationFlags();

  ConsoleMainMenu console_main_menu_;

  bool user_want_log_out_ = false;
  bool user_want_quit_ = false;
};

#endif  // CONSOLE_MAIN_MENU_PRESENTER_H
