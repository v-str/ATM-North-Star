#include <confirmation_frame.h>

#include <console_editor.h>

std::string ConfirmationFrame::kLoginString = "No text";
std::string ConfirmationFrame::kFrameSymbol = "#";

void ConfirmationFrame::SetFrame(const std::string& login_string,
                                 const std::string& frame_symbol) {
  kLoginString = login_string;
  kFrameSymbol = frame_symbol;
}

void ConfirmationFrame::DrawFrame(int loading_percent) {
  DrawHorizontalLine();
  DrawEmptyLine();
  DrawTextLine("       REGISTRATION CONFIRMED");
  DrawEmptyLine();
  DrawHorizontalLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawTextLine("creating account:");
  DrawLoginLine();
  DrawEmptyLine();
  DrawPercentLoadingLine(loading_percent);
  DrawEmptyLine();
  DrawHorizontalLine();
}

void ConfirmationFrame::DrawHorizontalLine() {
  std::string horizontal_line;
  for (int i = 0; i < kLineLength; ++i) {
    horizontal_line.append(kFrameSymbol);
  }

  DrawString(horizontal_line);
}

void ConfirmationFrame::DrawEmptyLine() {
  std::string empty_line = kFrameSymbol;

  for (int i = 0; i < kLineLength - 2; ++i) {
    empty_line.append(" ");
  }

  empty_line.append(kFrameSymbol);

  DrawString(empty_line);
}

void ConfirmationFrame::DrawTextLine(const std::string& text) {
  std::string text_line = kFrameSymbol;
  text_line.append(" ");
  text_line.append(text);

  int text_line_length = text_line.length();

  for (int i = 0; i < kLineLength - text_line_length - 1; ++i) {
    text_line.append(" ");
  }

  text_line.append(kFrameSymbol);

  DrawString(text_line);
}

void ConfirmationFrame::DrawLoginLine() {
  std::string login_line = kFrameSymbol + "  " + kLoginString;
  int free_space = kLineLength - login_line.length() - 1;

  for (int i = 0; i < free_space; ++i) {
    login_line.append(" ");
  }

  login_line.append(kFrameSymbol);

  DrawString(login_line);
}

void ConfirmationFrame::DrawPercentLoadingLine(int loading_percent) {
  std::string loading_line = kFrameSymbol;
  for (int i = 0; i < (kLineLength / 2) - 3; ++i) {
    loading_line.append(" ");
  }

  loading_line.append(std::to_string(loading_percent));
  loading_line.append("%");

  int free_space = kLineLength - loading_line.length() - 1;

  for (int i = 0; i < free_space; ++i) {
    loading_line.append(" ");
  }

  loading_line.append(kFrameSymbol);

  DrawString(loading_line);
}

void ConfirmationFrame::DrawString(const std::string& string) {
  ConsoleEditor::WriteText(string);
  ConsoleEditor::AddEmptyLineNTimes(1);
}
