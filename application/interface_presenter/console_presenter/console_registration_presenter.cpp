#include <console_registration_presenter.h>

#include <atm_interactor.h>
#include <process_reporter.h>

void ConsoleRegistrationPresenter::RunRegistrationMenu() {
  console_registration_menu_.RunRegistrationMenu();
  if (console_registration_menu_.IsUserWantToRegistrate()) {
    RunRegistration();
  }
}

bool ConsoleRegistrationPresenter::UserWantQuit() const {
  return is_user_want_quit_;
}

void ConsoleRegistrationPresenter::RunRegistration() {
  for (;;) {
    ResetManipulationFlag();
    ReceiveRegistrationDataFromUser();
    HandleRegistrationData();

    if (IsRegistrationActionCorrect()) {
      break;
    }
  }
}

void ConsoleRegistrationPresenter::ReceiveRegistrationDataFromUser() {
  console_registration_menu_.ReceiveRegistrationDataFromUser();
  login_string_ = console_registration_menu_.LoginString();
  password_string_ = console_registration_menu_.PasswordString();
}

void ConsoleRegistrationPresenter::HandleRegistrationData() {
  ATM::RegistrationStatus login_status =
      registration_handler_.HandleLoginString(login_string_);
  ATM::RegistrationStatus password_status =
      registration_handler_.HandlePasswordString(password_string_);

  console_registration_menu_.ShowRegistratoinReport(login_status,
                                                    password_status);

  if (registration_handler_.IsRegistrationDataCorrect()) {
    console_registration_menu_.RunRegistrationConfirmation();
  } else {
    console_registration_menu_.RunIncorrectRegistrationNotification();
  }
}

bool ConsoleRegistrationPresenter::IsRegistrationActionCorrect() {
  if (console_registration_menu_.IsRegistrationConfirmed()) {
    ShowRegistrationAnimation();
    RunMainMenu();
    return true;
  }
  if (console_registration_menu_.IsUserWantToInitialMenu()) {
    return true;
  }
  if (console_registration_menu_.IsUserWantToExitProgram()) {
    return is_user_want_quit_ = true;
  }
  return false;
}

void ConsoleRegistrationPresenter::ShowRegistrationAnimation() {
  ProcessReporter process_reporter_;
  console_registration_menu_.ShowConfirmationAnimation(
      login_string_, process_reporter_.ProcessReport());
}

void ConsoleRegistrationPresenter::RunMainMenu() {
  AtmInteractor::RegisterUser(login_string_, password_string_);
  main_menu_presenter_.RunMainMenu();
  is_user_want_quit_ = main_menu_presenter_.UserWantQuit();
}

void ConsoleRegistrationPresenter::ResetManipulationFlag() {
  is_user_want_quit_ = false;
}
