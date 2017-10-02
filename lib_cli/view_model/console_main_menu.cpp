#include <console_main_menu.h>

#include <application_messenger.h>
#include <main_menu_messenger.h>

ConsoleMainMenu::ConsoleMainMenu() {
  for (int i = kAccountInfo; i <= kQuit; ++i) {
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

bool ConsoleMainMenu::UserWantCreditCalculator() const {
  return user_item_choice_[kCreditCalculator];
}

bool ConsoleMainMenu::UserWantWithdraw() const {
  return user_item_choice_[kWithdrawal];
}

bool ConsoleMainMenu::UserWantQuit() const { return user_item_choice_[kQuit]; }

bool ConsoleMainMenu::UserWantLogOut() const {
  return user_item_choice_[kLogOut];
}

void ConsoleMainMenu::ProcessMenuUserInput() {
  for (;;) {
    ResetManipulationFlags();
    int user_input = user_input_handler_.GetDigitInputFromUser();

    if (IsUserInputValid(user_input)) {
      ActivateMenuItem(user_input);
      break;
    } else {
      ApplicationMessenger::ShowIncorrectMenuInput();
    }
  }
}

void ConsoleMainMenu::ResetManipulationFlags() {
  user_item_choice_.assign(user_item_choice_.size(), false);
}

void ConsoleMainMenu::ActivateMenuItem(int user_input) {
  user_item_choice_[user_input] = true;
}

bool ConsoleMainMenu::IsUserInputContainMenuItem() const {
  for (int item = kAccountInfo; item <= kQuit; ++item) {
    if (user_item_choice_[item] == true) {
      return true;
    }
  }
  return false;
}

bool ConsoleMainMenu::IsUserInputValid(int user_input) const {
  if (user_input >= kAccountInfo && user_input <= kQuit) {
    return true;
  }
  return false;
}
