#ifndef CONSOLE_INITIAL_PRESENTER_H
#define CONSOLE_INITIAL_PRESENTER_H

#include <console_description_menu.h>
#include <console_initial_menu.h>
#include <console_login_menu.h>
#include <console_registration_menu.h>

class ConsoleInitialPresenter {
 public:
  enum MenuItem { kQuit, kDemo, kRegistration, kLogin };

  void RunApplication();

 private:
  void RunSubMenu(ConsoleInitialMenu::SubMenu sub_menu);

  void RunLoginMenu();
  void RunDescriptionMenu();
  void RunRegistrationMenu();

  ConsoleInitialMenu initial_menu_;
  ConsoleLoginMenu login_menu_;
  ConsoleDescriptionMenu description_menu_;
  ConsoleRegistrationMenu registration_menu_;

  bool user_want_to_exit_ = false;
};

#endif  // CONSOLE_INITIAL_PRESENTER_H
