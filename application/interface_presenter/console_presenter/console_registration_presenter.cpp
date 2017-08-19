#include <console_registration_presenter.h>

void ConsoleRegistrationPresenter::RunRegistrationMenu() {
  registration_menu_.RunRegistrationMenu();
  if (registration_menu_.IsUserWantToRegistrate()) {
    BeginRegistration();
    // pass here data for atm_model
  }
  if (registration_menu_.IsUserWantToExitProgram()) {
    user_want_to_exit_ = true;
  }
}

bool ConsoleRegistrationPresenter::IsUserWantToExit() const {
  return user_want_to_exit_;
}

void ConsoleRegistrationPresenter::BeginRegistration() {
  registration_menu_.ReceiveRegistrationDataFromUser();

  login_string_ = registration_menu_.LoginString();
  password_string_ = registration_menu_.PasswordString();

  HandleRegistrationData();
}

void ConsoleRegistrationPresenter::HandleRegistrationData() {
  ATM::RegistrationStatus login_status =
      registration_handler_.HandleLoginString(login_string_);

  ATM::RegistrationStatus password_status =
      registration_handler_.HandlePasswordString(password_string_);

  registration_menu_.ShowLoginReport(login_status);
  registration_menu_.ShowPasswordReport(password_status);
}
