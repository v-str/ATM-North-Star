#include <interface_management.h>

#include <console_editor.h>
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

  ConsoleEditor::ClearScreen();
}

int InterfaceManager::GetMode() { return choice_; }

void InterfaceManager::WriteWelcome() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("version 1.0.1");
  ConsoleEditor::AddEmptyLineNTimes(4);
  ConsoleEditor::WriteTextWithDelayPerSymbol("Welcome to ATM program");
  ConsoleEditor::AddEmptyLineNTimes(3);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "Please, choose program mode:\n"
      "1. Console Mode\n"
      "2. Graphical Mode\n"
      "Enter: ");
}
