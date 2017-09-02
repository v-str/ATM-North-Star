#ifndef CONSOLE_REGISTRATION_PRESENTER_H
#define CONSOLE_REGISTRATION_PRESENTER_H

#include <string>

#include <atm_registration_handler.h>
#include <console_main_menu_presenter.h>
#include <console_registration_menu.h>

class ConsoleRegistrationPresenter {
 public:
  void RunRegistrationMenu();

  bool UserWantQuit() const;

 private:
  void BeginRegistration();
  void ReceiveRegistrationData();
  void HandleRegistrationData();
  bool UserRequestPerformed();

  void ShowRegistrationAnimation();
  void RunMainMenu();

  void ResetManipulationFlags();

  ConsoleRegistrationMenu registration_menu_;
  AtmRegistrationHandler registration_handler_;

  ConsoleMainMenuPresenter main_menu_presenter_;

  std::string login_string_;
  std::string password_string_;

  bool user_want_quit_ = false;
};

#endif  // CONSOLE_REGISTRATION_PRESENTER_H
