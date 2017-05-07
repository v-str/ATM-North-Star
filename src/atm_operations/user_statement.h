#ifndef USER_STATEMENT_H
#define USER_STATEMENT_H

#include <string>

#include <input/user_input.h>
#include <statement_messenger.h>

class AtmUser;

class UserStatement {
  using string = std::string;

 public:
  void ShowStatementFor(AtmUser* atm_user);

 private:
  static constexpr int kNull = 0;
  static constexpr int kSizeOfCheckField = 12;

  static string GetSpaces(int convertation_cash_to_space);
  static int NumberOfDigits(int value);

  StatementMessenger statement_messenger_;
};

#endif  // USER_STATEMENT_H
