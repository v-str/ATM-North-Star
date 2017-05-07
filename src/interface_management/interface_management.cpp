#include "interface_management.h"

#include <console_editor_duplicate.h>
#include <output_setup.h>

void InterfaceManager::SuggestMode() {
  for (;;) {
    WriteWelcome();
    choice_ = user_input_.GetValueFromUser();
    if (choice_ == 1) {
      OutputSetup::SetupTwoStreamsForOutput();
      break;
    } else if (choice_ == 2) {
      break;
    }
  }

  ConsoleEditorDuplicate::ClearScreen();
}

int InterfaceManager::GetMode() { return choice_; }

void InterfaceManager::WriteWelcome() {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("version 1.0.1");
  ConsoleEditorDuplicate::AddEmptyLineNTimes(4);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("Welcome to ATM program");
  ConsoleEditorDuplicate::AddEmptyLineNTimes(3);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "Please, choose program mode:\n"
      "1. Console Mode\n"
      "2. Graphical Mode\n"
      "Enter: ");
}
