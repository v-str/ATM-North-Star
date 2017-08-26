#include <console_registration_presenter.h>

void ConsoleRegistrationPresenter::RunRegistrationMenu() {
  registration_menu_.RunRegistrationMenu();
  if (registration_menu_.IsUserWantToRegistrate()) {
    BeginRegistration();
  }
  if (registration_menu_.IsUserWantToExitProgram()) {
    user_want_to_exit_ = true;
  }
}

bool ConsoleRegistrationPresenter::IsUserWantToExit() const {
  return user_want_to_exit_;
}

void ConsoleRegistrationPresenter::BeginRegistration() {
  for (;;) {
    ReceiveRegistrationData();
    HandleRegistrationData();

    if (UserRequestPerformed()) {
      break;
    }
  }
}

void ConsoleRegistrationPresenter::ReceiveRegistrationData() {
  registration_menu_.ReceiveRegistrationDataFromUser();

  login_string_ = registration_menu_.LoginString();
  password_string_ = registration_menu_.PasswordString();
}

void ConsoleRegistrationPresenter::HandleRegistrationData() {
  ATM::RegistrationStatus login_status =
      registration_handler_.HandleLoginString(login_string_);
  ATM::RegistrationStatus password_status =
      registration_handler_.HandlePasswordString(password_string_);

  registration_menu_.ShowRegistratoinReport(login_status, password_status);

  if (registration_handler_.IsRegistrationDataCorrect()) {
    registration_menu_.RunRegistrationConfirmation();
  } else {
    registration_menu_.RunIncorrectRegistrationNotification();
  }
}

bool ConsoleRegistrationPresenter::UserRequestPerformed() {
  if (registration_menu_.IsRegistrationConfirmed()) {
    registration_menu_.ShowConfirmationAnimation(login_string_);
    // main_menu_presenter_.RunMainMenu();
    return true;
  }

  if (registration_menu_.IsUserWantToInitialMenu()) {
    return true;
  }

  if (registration_menu_.IsUserWantToExitProgram()) {
    user_want_to_exit_ = true;
    return true;
  }
  return false;
}
