#include <statement_messenger.h>

#include <console_editor.h>

void StatementMessenger::ShowStatement(double amount_of_cash) {
  ConsoleEditor::ClearScreen();

  DrawFilledLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawTextLine("hell");
  DrawEmptyLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawFilledLine();

  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 2. Quit\n\t");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
  ConsoleEditor::IgnoreCinLine();
}

void StatementMessenger::DrawTextLine(const std::string& text) {
  int work_line_space = kFilledLineLength - 2;
  int free_line_space = work_line_space - text.length();
  std::string text_line = "\t#";
  if (IsLineSpaceEven(free_line_space)) {
    FillFirstLinePart(&text_line, free_line_space);
    text_line += text;
    for (int i = 0; i < free_line_space / 2; ++i) {
      text_line.append(" ");
    }
    text_line.append("#\n");
  }
  ConsoleEditor::WriteText(text_line);
}

void StatementMessenger::DrawFilledLine() {
  std::string filled_line = "\t";
  for (int i = 0; i < kFilledLineLength; ++i) {
    filled_line.append("#");
  }
  filled_line.append("\n");
  ConsoleEditor::WriteText(filled_line);
}

void StatementMessenger::DrawEmptyLine() {
  std::string empty_line = "\t#";
  for (int i = 0; i < kEmptyLineLength; ++i) {
    empty_line.append(" ");
  }
  empty_line.append("#\n");

  ConsoleEditor::WriteText(empty_line);
}

void StatementMessenger::FillFirstLinePart(std::string* text_line,
                                           int free_line_space) {
  for (int i = 0; i < free_line_space / 2; ++i) {
    text_line->append(" ");
  }
}

bool StatementMessenger::IsLineSpaceEven(int line_space) {
  return (line_space % 2) == 0;
}
