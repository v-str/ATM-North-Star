#include "user_statement.h"

#include <atm_user.h>
#include <console_editor.h>

void UserStatement::ShowStatementFor(AtmUser* atm_user) {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::ClearScreen();
  string spaces = GetSpaces(atm_user->Cash());
  int cash = atm_user->Cash();
  statement_messenger_.ShowStatement(cash, spaces);
}

UserStatement::string UserStatement::GetSpaces(int convertation_cash_to_space) {
  const char space = ' ';
  unsigned int amout_of_spaces = static_cast<unsigned int>(
      kSizeOfCheckField - NumberOfDigits(convertation_cash_to_space));
  return string(amout_of_spaces, space);
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
