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
    int user_input = user_input_handler_->GetDigitInputFromUser();

    DefineMenuItem(user_input);

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
      user_item_choice_[item] = true;
      break;
    }
  }
}

void ConsoleMainMenu::ResetManipulationFlags() {
  for (int i = kAccountInfo; i <= kQuit; ++i) {
    user_item_choice_[i] = false;
  }
}

bool ConsoleMainMenu::IsUserInputContainMenuItem() const {
  for (int item = kAccountInfo; item <= kQuit; ++item) {
    if (user_item_choice_[item] == true) {
      return true;
    }
  }
  return false;
}

void ConsoleMainMenu::FillMenuItemsVector() {}
