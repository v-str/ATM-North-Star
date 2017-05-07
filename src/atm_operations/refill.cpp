#include <refill.h>

#include <atm_user.h>
#include <console_editor.h>
#include <notice_messenger.h>

void Refill::StartRefillOperationFor(AtmUser* atm_user) {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::ClearScreen();
  refill_messenger_.ShowNotifyAboutCash();
  int money = user_input_.GetValueFromUser();
  if (money >= minimal_refill && money <= maximal_refill) {
    atm_user->AddCash(money);
    refill_messenger_.ShowUserBalance(atm_user->Cash());
  } else {
    NoticeMessenger::ShowIncorrectSum();
  }
}
