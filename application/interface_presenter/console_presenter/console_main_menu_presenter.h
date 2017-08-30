#ifndef CONSOLE_MAIN_MENU_PRESENTER_H
#define CONSOLE_MAIN_MENU_PRESENTER_H

#include <console_account_informer.h>
#include <console_main_menu.h>

class ConsoleMainMenuPresenter {
 public:
  void RunMainMenu();

  bool UserWantQuit() const;

 private:
  void PerformMenuItem();

  void ResetManipulationFlags();

  ConsoleMainMenu console_main_menu_;
  ConsoleAccountInformer account_informer_;

  bool user_want_log_out_ = false;
  bool user_want_quit_ = false;
};

#endif  // CONSOLE_MAIN_MENU_PRESENTER_H
