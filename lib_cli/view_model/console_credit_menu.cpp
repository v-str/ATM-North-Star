#include <console_credit_menu.h>

#include <credit_messenger.h>
#include <user_input_handler.h>

void ConsoleCreditMenu::RunCreditMenu() {
  CreditMessenger::DisplayCreditMenu();
  ProcessUserInput();
}

bool ConsoleCreditMenu::IsUserWantCredit() const { return user_want_credit_; }

bool ConsoleCreditMenu::IsUserWantCreditCalculator() const {
  return user_want_credit_calculator_;
}

bool ConsoleCreditMenu::IsUserWantMainMenu() const {
  return user_want_main_menu_;
}

bool ConsoleCreditMenu::IsUserWantQuit() const { return user_want_quit_; }

void ConsoleCreditMenu::ProcessUserInput() {
  for (;;) {
    UserInputHandler user_input_handler;
    int user_input = user_input_handler.GetDigitInputFromUser();

    if (IsUserInputContainMenuItem(user_input)) {
      break;
    } else {
      CreditMessenger::ShowIncorrectInput();
    }
  }
}

bool ConsoleCreditMenu::IsUserInputContainMenuItem(int user_input) {
  ResetManipulationFlags();

  if (user_input == kCredit) {
    return user_want_credit_ = true;
  }
  if (user_input == kCreditCalculator) {
    return user_want_credit_calculator_ = true;
  }
  if (user_input == kMainMenu) {
    return user_want_main_menu_ = true;
  }
  if (user_input == kQuit) {
    return user_want_quit_ = true;
  }
  return false;
}

void ConsoleCreditMenu::ResetManipulationFlags() {
  user_want_credit_ = false;
  user_want_credit_calculator_ = false;
  user_want_main_menu_ = false;
  user_want_quit_ = false;
}
