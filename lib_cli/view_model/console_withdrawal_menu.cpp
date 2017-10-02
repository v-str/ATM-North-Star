#include <console_withdrawal_menu.h>

#include <application_messenger.h>
#include <password_input_handler.h>
#include <user_input_handler.h>
#include <withdrawal_messenger.h>

void ConsoleWithdrawalMenu::RunWithdrawalMenu() {
  WithdrawalMessenger::ShowWithdrawalNotification();
  ProcessUserInput();
}

std::string ConsoleWithdrawalMenu::GetPasswordFromUser() const {
  WithdrawalMessenger::RequirePasswordMessage();
  std::string password_string;
  PasswordInputHandler password_user_handler_;
  password_string = password_user_handler_.GetPassword();

  return password_string;
}

int ConsoleWithdrawalMenu::SumOfWithdrawal() const {
  return sum_of_withdrawal_;
}

bool ConsoleWithdrawalMenu::UserWantMainMenu() const {
  return user_want_main_menu_;
}

bool ConsoleWithdrawalMenu::UserWantQuit() const { return user_want_quit_; }

void ConsoleWithdrawalMenu::ShowSuccessfulWithdrawal() const {
  WithdrawalMessenger::ShowSuccessfulWithdrawal();
  ApplicationMessenger::PressEnterToContinue();
}

void ConsoleWithdrawalMenu::ShowIncorrectWithdrawal() const {
  WithdrawalMessenger::IncorrectWithdrawalMessage();
  ApplicationMessenger::PressEnterToContinue();
}

void ConsoleWithdrawalMenu::ProcessUserInput() {
  ResetManipulationFlags();

  UserInputHandler user_input_handler_;
  int user_input = user_input_handler_.GetDigitInputFromUser();

  CheckUserInput(user_input);
}

void ConsoleWithdrawalMenu::CheckUserInput(int user_input) {
  if (user_input == kMainMenu) {
    user_want_main_menu_ = true;
  } else if (user_input == kQuit) {
    user_want_quit_ = true;
  } else {
    sum_of_withdrawal_ = user_input;
  }
}

void ConsoleWithdrawalMenu::ResetManipulationFlags() {
  user_want_main_menu_ = false;
  user_want_quit_ = false;
}
