#include <account_informator.h>

#include <atm_user.h>
#include <console_editor_duplicate.h>

void AccountInformator::DisplayAccountInformationFor(AtmUser* atm_user) {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(2);
  ConsoleEditorDuplicate::ClearScreen();
  screen_.DisplayLogin(atm_user->Login());
  screen_.DisplayPassword(atm_user->Password());
  screen_.DisplayCash(atm_user->Cash());
  screen_.DisplayCredit(atm_user->CreditSum());
  screen_.DisplayPayment(atm_user->MonthlyPayment());
  screen_.DisplayCreditMonth(atm_user->CreditTerm());
}
