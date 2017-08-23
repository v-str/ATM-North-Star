#include <confirmation_registration_messenger.h>

#include <console_editor.h>

std::string ConfirmationRegistrationMessenger::kTitle = "ATM NORTH STAR";
std::string ConfirmationRegistrationMessenger::kGratingSymbol = "#";

void ConfirmationRegistrationMessenger::ShowConfirmationMessage(
    const std::string& login_string) {
  WriteTitle();
  DrawConfirmationFrame();
}

void ConfirmationRegistrationMessenger::WriteTitle() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteText(kTitle);
  ConsoleEditor::AddEmptyLineNTimes(2);
}

void ConfirmationRegistrationMessenger::DrawConfirmationFrame() {
  DrawHorizontalLine();
  DrawEmptyLine();
}

void ConfirmationRegistrationMessenger::DrawHorizontalLine() {
  for (int i = 0; i < kLineLength; ++i) {
    ConsoleEditor::WriteText(kGratingSymbol);
  }
}

void ConfirmationRegistrationMessenger::DrawEmptyLine() {
  ConsoleEditor::WriteText(kGratingSymbol);

  for (int i = 0; i < kLineLength - 2; ++i) {
    ConsoleEditor::WriteText(" ");
  }

  ConsoleEditor::WriteText(kGratingSymbol);
}
