#include "user_statement.h"

void UserStatement::ShowStatement(AtmUser *atm_user) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  string spaces = GetSpaces(atm_user->get_cash());
  int cash = atm_user->get_cash();
  statement_messenger_.ShowStatement(cash, spaces);
}

UserStatement::string UserStatement::GetSpaces(
    int convertation_cash_to_space) {
  const char space = ' ';
  return string(kSizeOfCheckField - NumberOfDigits(convertation_cash_to_space),
                space);
}

int UserStatement::NumberOfDigits(int value) {
  int number_of_digits = kNull;
  if (value == kNull) {
    return number_of_digits = 1;
  } else {
    while (value != kNull) {
      ++number_of_digits;
      value /= 10;
    }
  }
  return number_of_digits;
}
