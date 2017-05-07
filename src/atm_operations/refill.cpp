#include <refill.h>

#include <atm_user.h>
#include <console_editor_duplicate.h>

void Refill::StartRefillOperationFor(AtmUser* atm_user) {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(2);
  ConsoleEditorDuplicate::ClearScreen();
  refill_messenger_.ShowNotifyAboutCash();
  int money = user_input_.GetValueFromUser();
  if (money >= minimal_refill && money <= maximal_refill) {
    atm_user->AddCash(money);
    refill_messenger_.ShowUserBalance(atm_user->Cash());
  } else {
    notice_messenger_.ShowIncorrectSum();
  }
}
