#ifndef USER_STATEMENT_H
#define USER_STATEMENT_H

#include <string>

#include "atm_user.h"
#include "console_editor.h"
#include "input/user_input.h"
#include "statement_messenger.h"

class UserStatement {
  using string = std::string;

 public:
  void ShowStatementFor(AtmUser* atm_user);

 private:
  static const int kNull = 0;
  static const int kSizeOfCheckField = 12;

  static string GetSpaces(int convertation_cash_to_space);
  static int NumberOfDigits(int value);

  StatementMessenger statement_messenger_;
  ConsoleEditor console_editor_;
};

#endif  // USER_STATEMENT_H
