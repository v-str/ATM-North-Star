#include <console_registration_menu.h>

#include <menu_input_handler.h>
#include <registration_messenger.h>
#include <user_input_handler.h>

ConsoleRegistrationMenu::~ConsoleRegistrationMenu() {}

void ConsoleRegistrationMenu::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ProcessMenuUserInput();
}

bool ConsoleRegistrationMenu::UserWantToRegistrate() const {
  return user_want_to_registrate_;
}

bool ConsoleRegistrationMenu::UserWantToInitialMEnu() const {
  return user_want_to_initial_menu_;
}

bool ConsoleRegistrationMenu::UserWantToExit() const {
  return user_want_to_exit_;
}

void ConsoleRegistrationMenu::ProcessMenuUserInput() {
  input_handler_ = std::unique_ptr<UserInputHandler>(new MenuInputHandler);
  for (;;) {
    int user_input = input_handler_->GetDigitInputFromUser();
    if (user_input == kRegistration) {
      user_want_to_registrate_ = true;
    } else if (user_input == kInitialMenu) {
      user_want_to_initial_menu_ = true;
    } else if (user_input == kSymbolQuit || user_input == kDigitQuit) {
      user_want_to_exit_ = true;
    } else {
      RegistrationMessenger::ShowIncorrectInput();
    }
  }
}
