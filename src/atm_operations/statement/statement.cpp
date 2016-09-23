#include "statement.h"

const int kSizeOfCheckField = 12;

bool UserStatement::ShowStatement(CashOperator &cash_operator) {
  utility_.ClearScreen();
  string spaces = GetSpaces(cash_operator.GetCash());
  int cash = cash_operator.GetCash();
  statement_messenger_.ShowStatement(cash, spaces);
  return user_input_.SuggestUserToExit();
}

UserStatement::string UserStatement::GetSpaces(int convertation_cash_to_space) const {
  const char space = ' ';
  return string(kSizeOfCheckField - NumberOfDigits(convertation_cash_to_space),
                space);
}

int UserStatement::NumberOfDigits(int value) const {
  int number_of_digits = 0;
  if (value == 0) {
    return number_of_digits = 1;
  } else {
    while (value != 0) {
      ++number_of_digits;
      value /= 10;
    }
  }
  return number_of_digits;
}