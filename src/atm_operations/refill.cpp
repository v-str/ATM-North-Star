#include "refill.h"

void Refill::StartRefillOperationFor(AtmUser *atm_user) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  refill_messenger_.ShowNotifyAboutCash();
  int money = user_input_.GetValueFromUser();
  if (money >= minimal_refill && money <= maximal_refill) {
    atm_user->AddCash(money);
    refill_messenger_.ShowUserBalance(atm_user->Cash());
  } else {
    notice_messenger_.ShowIncorrectSum();
  }
}
