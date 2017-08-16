#include <console_registration_menu.h>

#include <menu_input_handler.h>
#include <registration_messenger.h>
#include <user_input_handler.h>

ConsoleRegistrationMenu::ConsoleRegistrationMenu()
    : user_input_(new UserInputHandler), menu_input_(new MenuInputHandler) {}

ConsoleRegistrationMenu::~ConsoleRegistrationMenu() {}

void ConsoleRegistrationMenu::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
}
