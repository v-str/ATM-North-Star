#include <confirmation_registration_messenger.h>

#include <console_editor.h>

std::string ConfirmationRegistrationMessenger::kTitle = "ATM NORTH STAR";
std::string ConfirmationRegistrationMessenger::kGratingSymbol = "#";
std::string ConfirmationRegistrationMessenger::kConfirmationText =
    "CONFIRMATION ACCEPTED";
std::string ConfirmationRegistrationMessenger::kSpaceSymbol = " ";

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
  DrawConfirmationTextLine();
}

void ConfirmationRegistrationMessenger::DrawHorizontalLine() {
  for (int i = 0; i < kLineLength; ++i) {
    ConsoleEditor::WriteText(kGratingSymbol);
  }
}

void ConfirmationRegistrationMessenger::DrawEmptyLine() {
  std::string empty_space;
  for (int i = 0; i < kLineLength - 2; ++i) {
    empty_space += " ";
  }

  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(kGratingSymbol + empty_space + kGratingSymbol);
}

void ConfirmationRegistrationMessenger::DrawConfirmationTextLine() {
  std::string empty_space = "         ";

  std::string final_confirmation_string = kGratingSymbol + empty_space +
                                          kConfirmationText + empty_space +
                                          kGratingSymbol;

  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(final_confirmation_string);
}
