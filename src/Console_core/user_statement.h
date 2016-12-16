#ifndef USER_STATEMENT_H
#define USER_STATEMENT_H

#include "atm_user.h"
#include "console_editor.h"
#include "statement_messenger.h"
#include "user_input.h"

#include <string>

class UserStatement {
  using string = std::string;

 public:
  void ShowStatement(AtmUser &atm_user);

 private:
  static const int kNull = 0;
  static const int kSizeOfCheckField = 12;

  static string GetSpaces(int convertation_cash_to_space);
  static int NumberOfDigits(int value);

  UserInput user_input_;
  StatementMessenger statement_messenger_;
  ConsoleEditor console_editor_;
};

#endif  // USER_STATEMENT_H
