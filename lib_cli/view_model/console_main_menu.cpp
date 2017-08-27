#include <console_main_menu.h>

#include <main_menu_messenger.h>
#include <submenu_input_handler.h>

void ConsoleMainMenu::RunMainMenu() {
  MainMenuMessenger::ShowMainMenu();
  ProcessMenuUserInput();
}

bool ConsoleMainMenu::UserWantQuit() const { return user_want_quit_; }

bool ConsoleMainMenu::UserWantLogOut() const { return user_want_log_out_; }

bool ConsoleMainMenu::UserWantAccountSubMenu() const {
  return user_want_account_sub_menu_;
}

void ConsoleMainMenu::ProcessMenuUserInput() {
  user_input_handler_ =
      std::unique_ptr<UserInputHandler>(new SubMenuInputHandler);
  int user_input = 0;
  for (;;) {
    ResetManipulationFlags();

    user_input = user_input_handler_->GetDigitInputFromUser();

    if (IsUserInputContainSubMenu(user_input)) {
      break;
    } else {
      MainMenuMessenger::ShowIncorrectInput();
    }
  }
}

void ConsoleMainMenu::ResetManipulationFlags() {
  user_want_quit_ = false;
  user_want_log_out_ = false;
  user_want_account_sub_menu_ = false;
}

bool ConsoleMainMenu::IsUserInputContainSubMenu(int user_input) {
  if (user_input == kAccountInfo) {
    user_want_account_sub_menu_ = true;
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
