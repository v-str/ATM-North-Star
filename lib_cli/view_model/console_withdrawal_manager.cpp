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

bool ConsoleWithdrawalManager::UserWantMainMenu() const {
  return user_want_main_menu_;
}

bool ConsoleWithdrawalManager::UserWantQuit() const { return user_want_quit_; }

void ConsoleWithdrawalManager::ShowSuccessfulWithdrawal() const {
  WithdrawalMessenger::ShowSuccessfulWithdrawal();
}

void ConsoleWithdrawalManager::ShowIncorrectWithdrawal() const {
  WithdrawalMessenger::IncorrectWithdrawalMessage();
}

void ConsoleWithdrawalManager::ProcessUserInput() {
  ResetManipulationFlags();

  UserInputHandler user_input_handler_;
  int user_input = user_input_handler_.GetDigitInputFromUser();

  CheckUserInput(user_input);
}

void ConsoleWithdrawalManager::CheckUserInput(int user_input) {
  if (user_input == kMainMenu) {
    user_want_main_menu_ = true;
  } else if (user_input == kQuit) {
    user_want_quit_ = true;
  } else {
    sum_of_withdrawal_ = user_input;
  }
}

void ConsoleWithdrawalManager::ResetManipulationFlags() {
  user_want_main_menu_ = false;
  user_want_quit_ = false;
}
