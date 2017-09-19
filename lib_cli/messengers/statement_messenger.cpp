#include <statement_messenger.h>

#include <iomanip>
#include <sstream>

#include <console_editor.h>

void StatementMessenger::ShowStatement(double amount_of_cash) {
  ConsoleEditor::ClearScreen();

  DrawFilledLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawEmptyLine();
  DrawTextLine("Atm North Star");
  DrawEmptyLine();
  DrawEmptyLine();
  DrawTextLine("Green St. 28");
  DrawEmptyLine();
  DrawEmptyLine();
  DrawTextLine("Balance:     ");
  DrawTextLine(GetCashString(amount_of_cash));
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
  FillFirstLinePart(&text_line, free_line_space);
  text_line += text;
  AddTextLineRemainder(&text_line, free_line_space);
}

void StatementMessenger::DrawFilledLine() {
  std::string filled_line = "\t";
  FillLine(&filled_line, kFilledLineLength, "#");
  filled_line.append("\n");
  ConsoleEditor::WriteText(filled_line);
}

void StatementMessenger::DrawEmptyLine() {
  std::string empty_line = "\t#";
  FillLine(&empty_line, kEmptyLineLength, " ");
  empty_line.append("#\n");
  ConsoleEditor::WriteText(empty_line);
}

void StatementMessenger::FillFirstLinePart(std::string* text_line,
                                           int free_line_space) {
  FillLine(text_line, free_line_space / 2, " ");
}

void StatementMessenger::AddTextLineRemainder(std::string* text_line,
                                              int free_line_space) {
  if (IsLineSpaceEven(free_line_space)) {
    FillLine(text_line, free_line_space / 2, " ");
  } else {
    int rest_of_line = free_line_space / 2;
    FillLine(text_line, rest_of_line, " ");
  }
  text_line->append("#\n");
  ConsoleEditor::WriteText(*text_line);
}

void StatementMessenger::FillLine(std::string* text_line, int count_of_symbols,
                                  const std::string& symbol) {
  for (int i = 0; i < count_of_symbols; ++i) {
    text_line->append(symbol);
  }
}

bool StatementMessenger::IsLineSpaceEven(int line_space) {
  return (line_space % 2) == 0;
}

std::string StatementMessenger::GetCashString(double amount_of_cash) {
  std::stringstream conversion_stream;
  conversion_stream << std::fixed << std::setprecision(2) << amount_of_cash;

  return conversion_stream.str();
}
