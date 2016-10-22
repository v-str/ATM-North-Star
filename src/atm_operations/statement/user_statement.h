#ifndef USER_STATEMENT_H
#define USER_STATEMENT_H

#include <string>

#include "statement_messenger.h"
#include "system_utility.h"
#include "user_input.h"
#include "cash_operator.h"

class UserStatement {
  using string = std::string;

 public:
  void ShowStatement(CashOperator &cash_operator);

 private:
  static const int kNull = 0;
  static const int kSizeOfCheckField = 12;

  string GetSpaces(int convertation_cash_to_space) const;
  int NumberOfDigits(int value) const;

  SystemUtility utility_;
  UserInput user_input_;
  StatementMessenger statement_messenger_;
};

#endif  // USER_STATEMENT_H
