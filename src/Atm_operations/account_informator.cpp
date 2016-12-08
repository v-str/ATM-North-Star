#include "account_informator.h"
#include "system_utility.h"

void AccountInformator::DisplayAccountInformation(
    UserIdentifier &user_identifier, CashOperator &cash_operator) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  screen_.DisplayLogin(user_identifier.GetLogin());
  screen_.DisplayPassword(user_identifier.GetPassword());
  screen_.DisplayCash(cash_operator.GetCash());
  screen_.DisplayCredit(cash_operator.GetCredit());
  screen_.DisplayPayment(cash_operator.GetMonthlyPayment());
  screen_.DisplayCreditMonth(cash_operator.GetAmountOfCreditMonth());
}
