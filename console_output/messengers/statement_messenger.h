#ifndef STATEMENT_MESSENGER_H
#define STATEMENT_MESSENGER_H

#include "output_configuration/console_editor.h"

#include <string>

class StatementMessenger {
 public:
  void ShowStatement(int cash, const std::string &spaces) const;

 private:
  ConsoleEditor console_editor_;
};

#endif  // STATEMENT_MESSENGER_H
