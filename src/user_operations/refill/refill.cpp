#include "refill.h"

bool Refill::StartRefillOperation(CashOperator &cash_operator) {
  refill_messenger_.ShowNotifyAboutCash();
  int money = 0;
  cin >> money;
  if (money >= 10 && money <= 50000) {
    cash_operator.AddCash(money);
    refill_messenger_.ShowUserBalance(cash_operator.GetCash());
  } else {
    error_message_.NoticeAboutIncorrectSum();
  }
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}
