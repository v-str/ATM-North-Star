#include <statement_menu.h>

#include <statement_messenger.h>
#include <user_input_handler.h>

void StatementMenu::RunStatement(int amount_of_cash) {
  StatementMessenger::ShowStatement(amount_of_cash);
}

bool StatementMenu::UserWantQuit() const { return user_want_quit_; }

void StatementMenu::ProcessUserInput() {
  UserInputHandler user_input_handler;
  int user_input = user_input_handler.GetDigitInputFromUser();
}

void StatementMenu::CheckUserInput(int user_input) {
  ResetManipulationFlags();

  if (user_input == kMainMenu) {
    user_want_main_menu_ = true;
  }
  if (user_input == kQuit) {
    user_want_quit_ = true;
  }
}

void StatementMenu::ResetManipulationFlags() {
  user_want_main_menu_ = false;
  user_want_quit_ = false;
}
