#include <console_refill_menu.h>

#include <refill_messenger.h>

void ConsoleRefillMenu::RunRefillMenu() {
  RefillMessenger::ShowRefillNotification();
  ProcessUserInput();
}

void ConsoleRefillMenu::ShowCorrectRefillingNotification() const {
  RefillMessenger::ShowSuccessfulCashRefilling();
}

void ConsoleRefillMenu::ShowIncorrectRefillingNotification() const {
  RefillMessenger::ShowIncorrectRefillingMessage();
}

void ConsoleRefillMenu::ShowMainMenuQuit() const {
  RefillMessenger::ShowMainMenuQuit();
}

int ConsoleRefillMenu::SumOfCash() const { return sum_of_cash_; }

bool ConsoleRefillMenu::UserWantMainMenu() const {
  return user_want_main_menu_;
}

bool ConsoleRefillMenu::UserWantQuit() const { return user_want_quit_; }

void ConsoleRefillMenu::ProcessUserInput() {
  int user_input = 0;

  for (;;) {
    ResetManipulationFlags();

    user_input = user_input_handler_.GetDigitInputFromUser();

    if (IsUserInputCorrect(user_input)) {
      break;
    } else {
      RefillMessenger::ShowIncorrectInputMessage();
    }
  }
}

bool ConsoleRefillMenu::IsUserInputCorrect(int user_input) {
  if (user_input == kMainMenu) {
    return user_want_main_menu_ = true;
  }
  if (user_input == kQuit) {
    return user_want_quit_ = true;
  }
  if (user_input > kNull) {
    sum_of_cash_ = user_input;
    return true;
  }
  return false;
}

void ConsoleRefillMenu::ResetManipulationFlags() {
  user_want_main_menu_ = false;
  user_want_quit_ = false;
}
