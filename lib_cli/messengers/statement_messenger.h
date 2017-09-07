#ifndef STATEMENT_MESSENGER_H
#define STATEMENT_MESSENGER_H

class StatementMessenger {
 public:
  static void ShowStatement(int cash);

 private:
  static const int kLineLength = 18;
};

#endif  // STATEMENT_MESSENGER_H
