#include "console_withdrawal_manager.h"

#include <password_input_handler.h>
#include <user_input_handler.h>
#include <withdrawal_messenger.h>

void ConsoleWithdrawalManager::RunWithdrawalMenu() {
  WithdrawalMessenger::ShowWithdrawalNotification();
  ProcessUserInput();
}

std::string ConsoleWithdrawalManager::GetPasswordFromUser() const {
  WithdrawalMessenger::RequirePasswordMessage();
  std::string password_string;
  PasswordInputHandler password_user_handler_;
  password_string = password_user_handler_.GetPassword();

  return password_string;
}

int ConsoleWithdrawalManager::SumOfWithdrawal() const {
  return sum_of_withdrawal_;
}

bool ConsoleWithdrawalManager::UserWantQuit() const { return user_want_quit_; }

void ConsoleWithdrawalManager::ProcessUserInput() {
  int user_input = 0;

  for (;;) {
    ResetManipulationFlags();

    UserInputHandler user_input_handler_;
    user_input = user_input_handler_.GetDigitInputFromUser();

    if (IsUserInputCorrect(user_input)) {
      break;
    }

    WithdrawalMessenger::ShowIncorrectInputMessage();
  }
}

bool ConsoleWithdrawalManager::IsUserInputCorrect(int user_input) {
  if (user_input == kMainMenu) {
    return true;
  }
  if (user_input == kQuit) {
    return user_want_quit_ = true;
  }
  if (user_input > kNull) {
    sum_of_withdrawal_ = user_input;
    return true;
  }
  return false;
}

void ConsoleWithdrawalManager::ResetManipulationFlags() {
  user_want_quit_ = false;
}
