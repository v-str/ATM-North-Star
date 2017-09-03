#include <console_cash_refill_manager.h>

#include <refill_messenger.h>

void ConsoleCashRefillManager::RunRefillMenu() {
  RefillMessenger::ShowRefillNotification();
  ProcessUserInput();
}

bool ConsoleCashRefillManager::UserWantMainMenu() const {
  return user_want_main_menu_;
}

bool ConsoleCashRefillManager::UserWantQuit() const { return user_want_quit_; }

void ConsoleCashRefillManager::ProcessUserInput() {
  int user_input = 0;

  for (;;) {
    ResetManipulationFlags();

    user_input = user_input_handler_.GetDigitInputFromUser();

    if (IsUserInputContainSubMenu(user_input)) {
      break;
    }

    RefillMessenger::ShowIncorrectMessage();
  }
}

void ConsoleCashRefillManager::ResetManipulationFlags() {
  user_want_main_menu_ = false;
  user_want_quit_ = false;
  user_input_contain_cash_ = false;
}

bool ConsoleCashRefillManager::IsUserInputContainSubMenu(int user_input) {
  if (user_input == kMainMenu) {
    return user_want_main_menu_ = true;
  }
  if (user_input == kQuit) {
    return user_want_quit_ = true;
  }

  return false;
}
