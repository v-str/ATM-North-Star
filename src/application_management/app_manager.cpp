#include "app_manager.h"

#include <iostream>

void AppManager::SuggestAppMode() {
  for (;;) {
    WriteWelcome();
    int choice = user_input_.GetValueFromUser();
    if (choice == 1 || choice == 2) {
      break;
    }
  }

  console_editor_.ClearScreen();
}

void AppManager::WriteWelcome() {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelayPerSymbol("version 1.0.1");
  console_editor_.AddEmptyLineNTimes(4);
  console_editor_.WriteTextWithDelayPerSymbol("Welcome to program ATM");
  console_editor_.AddEmptyLineNTimes(3);
  console_editor_.WriteTextWithDelayPerSymbol(
      "Please, choose program mode:\n"
      "1. Console Mode\n"
      "2. Graphical Mode\n"
      "Enter: ");
}
