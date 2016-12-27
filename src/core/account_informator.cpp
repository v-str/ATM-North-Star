#include "account_informator.h"

void AccountInformator::DisplayAccountInformation(AtmUser *atm_user) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  screen_.DisplayLogin(atm_user->get_login());
  screen_.DisplayPassword(atm_user->get_password());
  screen_.DisplayCash(atm_user->get_cash());
  screen_.DisplayCredit(atm_user->get_credit());
  screen_.DisplayPayment(atm_user->get_monthly_payment());
  screen_.DisplayCreditMonth(atm_user->get_amount_of_credit_month());
}
