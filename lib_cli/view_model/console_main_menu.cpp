#include <console_main_menu.h>

#include <main_menu_messenger.h>
#include <submenu_input_handler.h>

void ConsoleMainMenu::RunMainMenu() {
  MainMenuMessenger::ShowMainMenu();
  ProcessMenuUserInput();
}

void ConsoleMainMenu::ProcessMenuUserInput() {
  user_input_handler_ =
      std::unique_ptr<UserInputHandler>(new SubMenuInputHandler);
  int user_input = 0;
  for (;;) {
    user_input = user_input_handler_->GetDigitInputFromUser();

    if (IsUserInputContainSubMenu(user_input)) {
      break;
    } else {
      MainMenuMessenger::ShowIncorrectInput();
    }
  }
}

bool ConsoleMainMenu::IsUserInputContainSubMenu(int user_input) {
  if (user_input == kAccountInfo) {
    return true;
  }
  if (user_input == kRefill) {
    return true;
  }
  if (user_input == kCreditApplication) {
    return true;
  }
  if (user_input == kWithdrawal) {
    return true;
  }
  if (user_input == kStatement) {
    return true;
  }
  if (user_input == kLogOut) {
    return true;
  }
  if (user_input == kQuit) {
    return true;
  }
  return false;
}
