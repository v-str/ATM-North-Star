#include <confirmation_registration_messenger.h>

#include <console_editor.h>

std::string ConfirmationRegistrationaAnimation::kTitle = "ATM NORTH STAR";
std::string ConfirmationRegistrationaAnimation::kGratingSymbol = "#";
std::string ConfirmationRegistrationaAnimation::kConfirmationText =
    "CONFIRMATION ACCEPTED";
std::string ConfirmationRegistrationaAnimation::kSpaceSymbol = " ";

void ConfirmationRegistrationaAnimation::ShowConfirmationMessage(
    const std::string& login_string) {
  kLoginString = login_string;

  WriteTitle();
  DrawConfirmationFrame();
}

void ConfirmationRegistrationaAnimation::WriteTitle() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteText(kTitle);
  ConsoleEditor::AddEmptyLineNTimes(2);
}

void ConfirmationRegistrationaAnimation::DrawConfirmationFrame() {
  DrawHorizontalLine();
  DrawEmptyLine();
  DrawConfirmationTextLine();
  DrawEmptyLine();
}

void ConfirmationRegistrationaAnimation::DrawHorizontalLine() {
  for (int i = 0; i < kLineLength; ++i) {
    ConsoleEditor::WriteText(kGratingSymbol);
  }
}

void ConfirmationRegistrationaAnimation::DrawEmptyLine() {
  std::string empty_space;
  for (int i = 0; i < kLineLength - 2; ++i) {
    empty_space += kSpaceSymbol;
  }

  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(kGratingSymbol + empty_space + kGratingSymbol);
}

void ConfirmationRegistrationaAnimation::DrawConfirmationTextLine() {
  std::string empty_space = "         ";

  std::string final_confirmation_string = kGratingSymbol + empty_space +
                                          kConfirmationText + empty_space +
                                          kGratingSymbol;

  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(final_confirmation_string);
}

void ConfirmationRegistrationaAnimation::DrawLoginStringLine() {
  int free_line_space =
      kLineLength - (kGratingSymbol.length() * 2) - kLoginString.length();
}
