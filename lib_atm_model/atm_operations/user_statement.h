#ifndef USER_STATEMENT_H
#define USER_STATEMENT_H

#include <string>

class AtmUser;

class UserStatement {
 public:
  void ShowStatementFor(AtmUser* atm_user);

 private:
  static constexpr int kNull = 0;
  static constexpr int kSizeOfCheckField = 12;

  static std::string GetSpaces(int convertation_cash_to_space);
  static int NumberOfDigits(int value);
};

#endif  // USER_STATEMENT_H
