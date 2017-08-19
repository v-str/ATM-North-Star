#ifndef CONSOLE_REGISTRATION_PRESENTER_H
#define CONSOLE_REGISTRATION_PRESENTER_H

#include <console_registration_menu.h>

class ConsoleRegistrationPresenter {
 public:
  void RunRegistrationMenu();

  bool IsUserWantToExit() const;

 private:
  ConsoleRegistrationMenu registration_menu_;

  bool user_want_to_exit_ = false;
};

#endif  // CONSOLE_REGISTRATION_PRESENTER_H
