#include "app_manager.h"

int AppManager::choice_ = 0;

void AppManager::SuggestMode() {
  for (;;) {
    WriteWelcome();
    choice_ = user_input_.GetValueFromUser();
    if (choice_ == 1 || choice_ == 2) {
      break;
    }
  }

  console_editor_.ClearScreen();
}

int AppManager::GetMode() { return choice_; }

void AppManager::WriteWelcome() {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelayPerSymbol("version 1.0.1");
  console_editor_.AddEmptyLineNTimes(4);
  console_editor_.WriteTextWithDelayPerSymbol("Welcome to ATM program");
  console_editor_.AddEmptyLineNTimes(3);
  console_editor_.WriteTextWithDelayPerSymbol(
      "Please, choose program mode:\n"
      "1. Console Mode\n"
      "2. Graphical Mode\n"
      "Enter: ");
}
