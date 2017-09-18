#include <statement_manager.h>

#include <statement_messenger.h>
#include <user_input_handler.h>

void StatementManager::RunStatement(int amount_of_cash) {
  StatementMessenger::ShowStatement(amount_of_cash);
}

bool StatementManager::UserWantQuit() const { return user_want_quit_; }

void StatementManager::ProcessUserInput() {
  UserInputHandler user_input_handler;
  int user_input = user_input_handler.GetDigitInputFromUser();
}

void StatementManager::CheckUserInput(int user_input) {
  ResetManipulationFlags();

  if (user_input == kMainMenu) {
    user_want_main_menu_ = true;
  }
  if (user_input == kQuit) {
    user_want_quit_ = true;
  }
}

void StatementManager::ResetManipulationFlags() {
  user_want_main_menu_ = false;
  user_want_quit_ = false;
}
