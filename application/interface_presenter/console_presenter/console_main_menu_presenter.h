#ifndef CONSOLE_MAIN_MENU_PRESENTER_H
#define CONSOLE_MAIN_MENU_PRESENTER_H

#include <console_account_informer.h>
#include <console_main_menu.h>

class ConsoleMainMenuPresenter {
 public:
  void RunMainMenu();

 private:
  ConsoleMainMenu main_menu_;
  ConsoleAccountInformer account_informer_;
};

#endif  // CONSOLE_MAIN_MENU_PRESENTER_H
