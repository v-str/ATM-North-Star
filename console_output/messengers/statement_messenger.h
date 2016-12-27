#ifndef STATEMENT_MESSENGER_H
#define STATEMENT_MESSENGER_H

#include <string>

#include "console_editor.h"

class StatementMessenger {
 public:
  void ShowStatement(int cash, const std::string &spaces) const;

 private:
  ConsoleEditor console_editor_;
};

#endif  // STATEMENT_MESSENGER_H
