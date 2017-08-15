#include <console_initial_menu.h>

#include <initial_messenger.h>

void ConsoleInitialMenu::RunInitialMenu() {
  DisplaySplashScreen();
  DisplayInitialMenu();
  SuggestInputSubMenu();
}

void ConsoleInitialMenu::DisplayFarewellMessage() {
  InitialMessenger::FarewellMessage();
}

int ConsoleInitialMenu::GetSubMenu() const { return sub_menu_input_; }

void ConsoleInitialMenu::SuggestInputSubMenu() {
  for (;;) {
    sub_menu_input_ = input_handler_.GetDigitInputFromUser();

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
