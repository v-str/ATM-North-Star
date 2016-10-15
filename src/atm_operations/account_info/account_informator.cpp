#include "account_informator.h"

void AccountInformator::DisplayAccountInformation(
    UserIdentifier &user_identifier, CashOperator &cash_operator) {
  screen_.DisplayLogin(user_identifier.GetLogin());
  screen_.DisplayPassword(user_identifier.GetPassword());
  screen_.DisplayCash(cash_operator.GetCash());
  screen_.DisplayCredit(cash_operator.GetCredit());
  screen_.DisplayPayment(cash_operator.GetMonthlyPayment());
  screen_.DisplayCreditMonth(cash_operator.GetAmountOfCreditMonth());
}
