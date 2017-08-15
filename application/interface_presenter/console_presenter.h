#ifndef CONSOLE_INTERFACE_PRESENTER_H
#define CONSOLE_INTERFACE_PRESENTER_H

#include <memory>

#include <console_description_menu.h>
#include <console_initial_menu.h>
#include <console_login_menu.h>
#include <console_registration_menu.h>

class ConsolePresenter {
 public:
  ConsolePresenter();

  enum MenuPoints { kQuit, kDemo, kRegistration, kLogin };

  void RunApplication();

 private:
  void RunSubMenu(int sub_menu);

  std::unique_ptr<ConsoleInitialMenu> initial_menu_;

  ConsoleLoginMenu login_menu_;
  ConsoleDescriptionMenu description_menu_;
  ConsoleRegistrationMenu registration_menu_;
};

#endif  // CONSOLE_INTERFACE_PRESENTER_H
