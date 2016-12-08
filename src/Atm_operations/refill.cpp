#include "refill.h"
#include "system_utility.h"

void Refill::StartRefillOperation(CashOperator &cash_operator) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  refill_messenger_.ShowNotifyAboutCash();
  int money = user_input_.GetValueFromUser();
  if (money >= minimal_refill && money <= maximal_refill) {
    cash_operator.AddCash(money);
    refill_messenger_.ShowUserBalance(cash_operator.GetCash());
  } else {
    notice_messenger_.ShowIncorrectSum();
  }
}
