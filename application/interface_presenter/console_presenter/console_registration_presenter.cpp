#include <console_registration_presenter.h>

#include <string>

void ConsoleRegistrationPresenter::RunRegistrationMenu() {
  registration_menu_.RunRegistrationMenu();
  if (registration_menu_.IsUserWantToRegistrate()) {
    registration_menu_.ReceiveRegistrationDataFromUser();
    std::string login = registration_menu_.LoginString();
    std::string password = registration_menu_.PasswordString();

    // pass here data for atm_model

  } else if (registration_menu_.IsUserWantToExitProgram()) {
    user_want_to_exit_ = true;
  }
}
