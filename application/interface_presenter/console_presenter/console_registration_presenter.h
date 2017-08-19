#ifndef CONSOLE_REGISTRATION_PRESENTER_H
#define CONSOLE_REGISTRATION_PRESENTER_H

#include <atm_registration_handler.h>
#include <console_registration_menu.h>

class ConsoleRegistrationPresenter {
 public:
  void RunRegistrationMenu();

  bool IsUserWantToExit() const;

 private:
  void BeginRegistration();

  ConsoleRegistrationMenu registration_menu_;
  AtmRegistrationHandler registration_handler_;

  bool user_want_to_exit_ = false;
};

#endif  // CONSOLE_REGISTRATION_PRESENTER_H
