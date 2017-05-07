#ifndef STATEMENT_MESSENGER_H
#define STATEMENT_MESSENGER_H

#include <string>

class StatementMessenger {
 public:
  void ShowStatement(int cash, const std::string& spaces) const;
};

#endif  // STATEMENT_MESSENGER_H
