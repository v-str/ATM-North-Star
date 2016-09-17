#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>

#include "cash_operator.h"
#include "system_utility.h"
#include "user_input.h"
#include "statement_messenger.h"

class UserStatement {
  using string = std::string;

 public:
  bool ShowStatement(CashOperator &cash_operator);

 private:
  string GetSpaces(int convertation_cash_to_space) const;
  int NumberOfDigits(int value) const;

  SystemUtility utility_;
  UserInput user_input_;
  StatementMessenger statement_messenger_;
};

#endif  // STATEMENT_H
