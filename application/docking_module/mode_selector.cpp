#include <mode_selector.h>

#include <console_editor.h>
#include <output_setup.h>

void ModeSelector::SuggestMode() {
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

int ModeSelector::GetMode() { return choice_; }

void ModeSelector::WriteWelcome() {
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
