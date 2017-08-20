#include <console_registration_menu.h>

#include <menu_input_handler.h>
#include <user_input_handler.h>

ConsoleRegistrationMenu::~ConsoleRegistrationMenu() {}

void ConsoleRegistrationMenu::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ProcessMenuUserInput(user_want_to_registrate_);
}

void ConsoleRegistrationMenu::ReceiveRegistrationDataFromUser() {
  input_handler_ = std::unique_ptr<UserInputHandler>(new UserInputHandler);
  RegistrationMessenger::ClearScreen();
  RegistrationMessenger::ShowRegistrationLogo();
  GetLoginStringFromUser();
  GetPasswordStringFromUser();
}

void ConsoleRegistrationMenu::ShowConfirmRegistration() {
  RegistrationMessenger::ShowConfirmationMessage();
  ProcessMenuUserInput(registration_confirmed_);
}

void ConsoleRegistrationMenu::ShowIncorrectRegistration() {
  RegistrationMessenger::IncorrectRegistrationNotification();
  ProcessMenuUserInput(user_want_to_repeat_registration_);
}

std::string ConsoleRegistrationMenu::LoginString() const { return login_; }

std::string ConsoleRegistrationMenu::PasswordString() const {
  return password_;
}

bool ConsoleRegistrationMenu::IsUserWantToRegistrate() const {
  return user_want_to_registrate_;
}

bool ConsoleRegistrationMenu::IsUserWantToRepeatRegistrate() const {
  return user_want_to_repeat_registration_;
}

bool ConsoleRegistrationMenu::IsUserWantToExitProgram() const {
  return user_want_to_exit_;
}

bool ConsoleRegistrationMenu::IsRegistrationConfirmed() const {
  return registration_confirmed_;
}

void ConsoleRegistrationMenu::ShowLoginReport(
    const RegistrationReporter::RegistrationStatus login) {
  reporter_.ShowLoginReport(login);
}

void ConsoleRegistrationMenu::ShowPasswordReport(
    const RegistrationReporter::RegistrationStatus password) {
  reporter_.ShowPasswordReport(password);
}

void ConsoleRegistrationMenu::ProcessMenuUserInput(bool& changing_action) {
  input_handler_ = std::unique_ptr<UserInputHandler>(new MenuInputHandler);
  for (;;) {
    ResetManipulationFlags();
    int user_input = input_handler_->GetDigitInputFromUser();
    if (user_input == kNextAction) {
      changing_action = true;
      break;
    } else if (user_input == kInitialMenu) {
      break;
    } else if (user_input == kSymbolQuit || user_input == kDigitQuit) {
      user_want_to_exit_ = true;
      break;
    } else {
      RegistrationMessenger::ShowIncorrectInput();
    }
  }
}

void ConsoleRegistrationMenu::ResetManipulationFlags() {
  user_want_to_registrate_ = false;
  user_want_to_exit_ = false;
  registration_confirmed_ = false;
  user_want_to_repeat_registration_ = false;
}

void ConsoleRegistrationMenu::GetLoginStringFromUser() {
  RegistrationMessenger::ShowLoginTitle();
  login_ = input_handler_->GetStringInputFromUser();
}

void ConsoleRegistrationMenu::GetPasswordStringFromUser() {
  RegistrationMessenger::ShowPasswordTitle();
  password_ = input_handler_->GetStringInputFromUser();
}
