#ifndef STATEMENT_MESSENGER_H
#define STATEMENT_MESSENGER_H

class StatementMessenger {
 public:
  static void ShowStatement(double amount_of_cash);

 private:
  static void DrawEmptyLine();

  static const int kLineLength = 18;
};

#endif  // STATEMENT_MESSENGER_H
