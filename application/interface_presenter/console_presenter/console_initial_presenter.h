#ifndef CONSOLE_INITIAL_PRESENTER_H
#define CONSOLE_INITIAL_PRESENTER_H

#include <console_initial_menu.h>
#include <console_login_menu.h>

#include <console_registration_presenter.h>

class ConsoleInitialPresenter {
 public:
  void RunApplication();

 private:
  void RunSubMenu(ConsoleInitialMenu::SubMenu sub_menu);

  void RunLoginMenu();
  void ShowDescription();
  void RunRegistrationMenu();

  ConsoleInitialMenu initial_menu_;
  ConsoleLoginMenu login_menu_;

  ConsoleRegistrationPresenter registration_presenter_;

  bool user_want_to_quit_ = false;
};

#endif  // CONSOLE_INITIAL_PRESENTER_H
