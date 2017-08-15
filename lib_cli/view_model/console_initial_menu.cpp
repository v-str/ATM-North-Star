#include <console_initial_menu.h>

#include <iostream>

#include <console_description_menu.h>
#include <console_login_menu.h>
#include <initial_messenger.h>
#include <menu_input_handler.h>

ConsoleInitialMenu::ConsoleInitialMenu()
    : input_handler_(new MenuInputHandler),
      login_menu_(new ConsoleLoginMenu),
      description_menu_(new ConsoleDescriptionMenu) {}

ConsoleInitialMenu::~ConsoleInitialMenu() {
  delete input_handler_;
  delete login_menu_;
  //  delete registration_menu_;
  delete description_menu_;
}

void ConsoleInitialMenu::RunInitialMenu() {
  DisplaySplashScreen();
  DisplayInitialMenu();
  SuggestInputSubMenu();
}

void ConsoleInitialMenu::RunLoginMenu() { login_menu_->RunLoginMenu(); }

void ConsoleInitialMenu::RunRegistrationMenu() {
  //  registration_menu_->RunRegistrationMenu();
}

void ConsoleInitialMenu::RunDescriptionMenu() {
  description_menu_->RunDemoMenu();
}

void ConsoleInitialMenu::DisplayFarewellMessage() {
  InitialMessenger::FarewellMessage();
}

int ConsoleInitialMenu::GetSubMenu() const { return sub_menu_input_; }

void ConsoleInitialMenu::SuggestInputSubMenu() {
  for (;;) {
    sub_menu_input_ = input_handler_->GetDigitInputFromUser();

    if (IsInputContainSubMenu()) {
      break;
    } else {
      InitialMessenger::ShowIncorrectMenuInput();
    }
  }
}

void ConsoleInitialMenu::DisplaySplashScreen() const {
  InitialMessenger::DisplaySplashScreen();
}

void ConsoleInitialMenu::DisplayInitialMenu() const {
  InitialMessenger::DisplayInitialMenu();
}

bool ConsoleInitialMenu::IsInputContainSubMenu() {
  if (sub_menu_input_ == kLoginMenu) {
    return true;
  }
  if (sub_menu_input_ == kRegistrationMenu) {
    return true;
  }
  if (sub_menu_input_ == kDemoMenu) {
    return true;
  }
  if (sub_menu_input_ == kExit) {
    return true;
  }
  return false;
}
