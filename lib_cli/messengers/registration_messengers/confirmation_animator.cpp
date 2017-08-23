#include <confirmation_animator.h>

#include <console_editor.h>

std::string ConfirmationAnimator::kTitle = "ATM NORTH STAR";
std::string ConfirmationAnimator::kGratingSymbol = "#";
std::string ConfirmationAnimator::kConfirmationText = "CONFIRMATION ACCEPTED";
std::string ConfirmationAnimator::kSpaceSymbol = " ";
std::string ConfirmationAnimator::kLoginString = "";

void ConfirmationAnimator::ShowConfirmationMessage(
    const std::string& login_string) {
  kLoginString = login_string;

  WriteTitle();
  DrawConfirmationFrame();
}

void ConfirmationAnimator::WriteTitle() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteText(kTitle);
  ConsoleEditor::AddEmptyLineNTimes(2);
}

void ConfirmationAnimator::DrawConfirmationFrame() {
  DrawHorizontalLine();
  DrawEmptyLine();
  DrawConfirmationTextLine();
  DrawEmptyLine();
}

void ConfirmationAnimator::DrawHorizontalLine() {
  for (int i = 0; i < kLineLength; ++i) {
    ConsoleEditor::WriteText(kGratingSymbol);
  }
}

void ConfirmationAnimator::DrawEmptyLine() {
  std::string empty_space;
  for (int i = 0; i < kLineLength - 2; ++i) {
    empty_space += kSpaceSymbol;
  }

  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(kGratingSymbol + empty_space + kGratingSymbol);
}

void ConfirmationAnimator::DrawConfirmationTextLine() {
  std::string empty_space = "         ";

  std::string final_confirmation_string = kGratingSymbol + empty_space +
                                          kConfirmationText + empty_space +
                                          kGratingSymbol;

  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(final_confirmation_string);
}

void ConfirmationAnimator::DrawLoginStringLine() {
  int free_line_space =
      kLineLength - (kGratingSymbol.length() * 2) - kLoginString.length();
}
