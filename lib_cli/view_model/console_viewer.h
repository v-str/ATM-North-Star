#ifndef CONSOLE_VIEWER_H
#define CONSOLE_VIEWER_H

#include <console_description_menu.h>
#include <console_initial_menu.h>
#include <console_login_menu.h>
#include <console_registration_menu.h>

class ConsoleViewer {
 public:
  enum MenuItem { kQuit, kDemo, kRegistration, kLogin };

  void RunApplication();

 protected:
  void RunSubMenu(int sub_menu);

 private:
  ConsoleInitialMenu initial_menu_;
  ConsoleLoginMenu login_menu_;
  ConsoleDescriptionMenu description_menu_;
  ConsoleRegistrationMenu registration_menu_;

  bool user_want_exit_ = false;
};

#endif  // CONSOLE_VIEWER_H
