#include <console_initial_menu.h>

#include <initial_messenger.h>

void ConsoleInitialMenu::RunInitialMenu() {
  InitialMessenger::DisplayInitialMenu();
  SuggestInputSubMenu();
}

void ConsoleInitialMenu::DisplayFarewellMessage() const {
  InitialMessenger::FarewellMessage();
}

ConsoleInitialMenu::SubMenu ConsoleInitialMenu::GetSubMenu() {
  return static_cast<ConsoleInitialMenu::SubMenu>(sub_menu_input_);
}

void ConsoleInitialMenu::SuggestInputSubMenu() {
  for (;;) {
    sub_menu_input_ = user_input_handler_.GetDigitInputFromUser();
    if (IsInputContainSubMenu()) {
      break;
    } else {
      InitialMessenger::ShowIncorrectMenuInput();
    }
  }
}

void ConsoleInitialMenu::RunSplashScreen() const {
  InitialMessenger::DisplaySplashScreen();
}

bool ConsoleInitialMenu::IsInputContainSubMenu() {
  if (sub_menu_input_ == kLoginMenu) {
    return true;
  }
  if (sub_menu_input_ == kRegistrationMenu) {
    return true;
  }
  if (sub_menu_input_ == kDescriptionMenu) {
    return true;
  }
  if (sub_menu_input_ == kQuit) {
    return true;
  }
  return false;
}
