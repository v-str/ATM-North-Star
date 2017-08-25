#include <confirmation_frame.h>

#include <console_editor.h>

std::string ConfirmationFrame::kText = "No text";
std::string ConfirmationFrame::kFrameSymbol = "#";

void ConfirmationFrame::SetFrame(const std::string& text,
                                 const std::string& frame_symbol) {
  kText = text;
  kFrameSymbol = frame_symbol;
}

void ConfirmationFrame::DrawFrame(int loading_percent) {
  DrawHorizontalLine();
  DrawEmptyLine();
}

void ConfirmationFrame::DrawHorizontalLine() {
  std::string horizontal_line;
  for (int i = 0; i < kLineLength; ++i) {
    horizontal_line.append(kFrameSymbol);
  }

  ConsoleEditor::WriteText(horizontal_line);
  ConsoleEditor::AddEmptyLineNTimes(1);
}

void ConfirmationFrame::DrawEmptyLine() {
  std::string empty_line = kFrameSymbol;

  for (int i = 0; i < kLineLength - 2; ++i) {
    empty_line.append(" ");
  }

  empty_line.append(kFrameSymbol);

  ConsoleEditor::WriteText(empty_line);
  ConsoleEditor::AddEmptyLineNTimes(1);
}
