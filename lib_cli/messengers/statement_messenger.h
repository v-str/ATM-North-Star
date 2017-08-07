#ifndef STATEMENT_MESSENGER_H
#define STATEMENT_MESSENGER_H

#include <string>

class StatementMessenger {
 public:
  static void ShowStatement(int cash, const std::string& spaces);
};

#endif  // STATEMENT_MESSENGER_H
