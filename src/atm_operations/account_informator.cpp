#include "account_informator.h"

void AccountInformator::DisplayAccountInformationFor(AtmUser *atm_user) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  screen_.DisplayLogin(atm_user->Login());
  screen_.DisplayPassword(atm_user->Password());
  screen_.DisplayCash(atm_user->Cash());
  screen_.DisplayCredit(atm_user->CreditSum());
  screen_.DisplayPayment(atm_user->MonthlyPayment());
  screen_.DisplayCreditMonth(atm_user->CreditTerm());
}
