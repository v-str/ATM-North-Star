#ifndef CONSOLE_REGISTRATION_PRESENTER_H
#define CONSOLE_REGISTRATION_PRESENTER_H

#include <string>

#include <atm_registration_handler.h>
#include <console_registration_menu.h>

class ConsoleRegistrationPresenter {
 public:
  void RunRegistrationMenu();

  bool IsUserWantToExit() const;

 private:
  void BeginRegistration();
  void ReceiveRegistrationData();
  void HandleRegistrationData();
  bool UserRequestPerformed();

  ConsoleRegistrationMenu registration_menu_;
  AtmRegistrationHandler registration_handler_;

  std::string login_string_;
  std::string password_string_;

  bool user_want_to_exit_ = false;
};

#endif  // CONSOLE_REGISTRATION_PRESENTER_H
