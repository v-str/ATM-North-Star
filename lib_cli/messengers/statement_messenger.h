#ifndef STATEMENT_MESSENGER_H
#define STATEMENT_MESSENGER_H

#include <string>

class StatementMessenger {
 public:
  static void ShowStatement(double amount_of_cash);

 private:
  static void DrawTextLine(const std::string &text);
  static void DrawFilledLine();
  static void DrawEmptyLine();

  static void FillFirstLinePart(std::string *text_line, int free_line_space);
  static void AddTextLineRemainder(std::string *text_line, int free_line_space);

  static void FillLine(std::string *text_line, int count_of_symbols,
                       const std::string &symbol);

  static bool IsLineSpaceEven(int line_space);

  static const int kFilledLineLength = 20;
  static const int kEmptyLineLength = 18;
};

#endif  // STATEMENT_MESSENGER_H
