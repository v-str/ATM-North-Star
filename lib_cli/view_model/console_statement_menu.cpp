﻿#include <console_statement_menu.h>

#include <statement_messenger.h>
#include <user_input_handler.h>

void ConsoleStatementMenu::RunStatement(int amount_of_cash) {
  StatementMessenger::ShowStatement(amount_of_cash);
  ProcessUserInput();
}

bool ConsoleStatementMenu::UserWantQuit() const { return user_want_quit_; }

void ConsoleStatementMenu::ProcessUserInput() {
  UserInputHandler user_input_handler;

  for (;;) {
    int user_input = user_input_handler.GetDigitInputFromUser();
    if (IsUserInputCorrect(user_input)) {
      break;
    }
    StatementMessenger::ShowIncorrectInput();
  }
}

bool ConsoleStatementMenu::IsUserInputCorrect(int user_input) {
  ResetManipulationFlags();

  if (user_input == kMainMenu) {
    return user_want_main_menu_ = true;
  }
  if (user_input == kQuit) {
    return user_want_quit_ = true;
  }
  return false;
}

void ConsoleStatementMenu::ResetManipulationFlags() {
  user_want_main_menu_ = false;
  user_want_quit_ = false;
}