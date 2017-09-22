#include <console_main_menu.h>

#include <main_menu_messenger.h>

ConsoleMainMenu::ConsoleMainMenu() {
  for (int i = 0; i <= kQuit; ++i) {
    user_item_choice_.push_back(false);
  }
}

void ConsoleMainMenu::RunMainMenu() {
  MainMenuMessenger::ShowMainMenu();
  ProcessMenuUserInput();
}

void ConsoleMainMenu::DisplayLogOutMessage() const {
  MainMenuMessenger::LogOutMessage();
}

bool ConsoleMainMenu::UserWantAccountInfo() const {
  return user_item_choice_[kAccountInfo];
}

bool ConsoleMainMenu::UserWantRefill() const {
  return user_item_choice_[kRefill];
}

bool ConsoleMainMenu::UserWantCredit() const {
  return user_item_choice_[kCredit];
}

bool ConsoleMainMenu::UserWantWithdraw() const {
  return user_item_choice_[kWithdrawal];
}

bool ConsoleMainMenu::UserWantStatement() const {
  return user_item_choice_[kStatement];
}

bool ConsoleMainMenu::UserWantQuit() const { return user_item_choice_[kQuit]; }

bool ConsoleMainMenu::UserWantLogOut() const {
  return user_item_choice_[kLogOut];
}

void ConsoleMainMenu::ProcessMenuUserInput() {
  for (;;) {
    user_input_ = user_input_handler_->GetDigitInputFromUser();

    DefineMenuItem(user_input_);

    if (IsUserInputContainMenuItem()) {
      break;
    } else {
      MainMenuMessenger::ShowIncorrectInput();
    }
  }
}

void ConsoleMainMenu::DefineMenuItem(int user_input) {
  ResetManipulationFlags();

  for (int item = kAccountInfo; item <= kQuit; ++item) {
    if (user_input == item) {
      user_input_contain_menu_item_ = true;
      user_item_choice_[item] = true;
      break;
    } else {
      user_input_contain_menu_item_ = false;
    }
  }
}

void ConsoleMainMenu::ResetManipulationFlags() {
  for (int i = kAccountInfo; i <= kQuit; ++i) {
    user_item_choice_[i] = false;
  }
}

bool ConsoleMainMenu::IsUserInputContainMenuItem() const {
  return user_input_contain_menu_item_;
}

void ConsoleMainMenu::FillMenuItemsVector() {}
