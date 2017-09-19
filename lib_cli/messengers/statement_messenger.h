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

  static const int kFilledLineLength = 20;
  static const int kEmptyLineLength = 18;
};

#endif  // STATEMENT_MESSENGER_H
