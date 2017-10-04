#include <console_registration_presenter.h>

#include <atm_interactor.h>
#include <process_reporter.h>

void ConsoleRegistrationPresenter::RunRegistrationMenu() {
  console_registration_menu_.RunRegistrationMenu();
  if (console_registration_menu_.IsUserWantToRegistrate()) {
    RunRegistration();
  }
  if (console_registration_menu_.IsUserWantToExitProgram()) {
    is_user_want_quit_ = true;
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
  password_tooltip_ = console_registration_menu_.PasswordTooltip();
}

void ConsoleRegistrationPresenter::HandleRegistrationData() {
  PassRegistrationDataInCore();

  console_registration_menu_.ShowRegistratoinReport(login_status_,
                                                    password_status_);
  console_registration_menu_.ShowPasswordTooltipReport(
      registration_handler_.PasswordTooltipCondition());

  if (registration_handler_.IsRegistrationDataCorrect()) {
    console_registration_menu_.RunRegistrationConfirmation();
  } else {
    console_registration_menu_.RunIncorrectRegistrationNotification();
  }
}

void ConsoleRegistrationPresenter::PassRegistrationDataInCore() {
  login_status_ = registration_handler_.HandleLoginString(login_string_);
  password_status_ =
      registration_handler_.HandlePasswordString(password_string_);
  registration_handler_.HandlePasswordTooltip(password_tooltip_);
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
  AtmInteractor::RegisterUser(login_string_, password_string_,
                              password_tooltip_);
  main_menu_presenter_.RunMainMenu();
  is_user_want_quit_ = main_menu_presenter_.UserWantQuit();
}

void ConsoleRegistrationPresenter::ResetManipulationFlag() {
  is_user_want_quit_ = false;
}
