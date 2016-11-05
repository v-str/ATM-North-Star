#include "refill.h"

void Refill::StartRefillOperation(CashOperator &cash_operator) {
  utility_.ClearScreen();
  refill_messenger_.ShowNotifyAboutCash();
  int money = kNull;
  std::cin >> money;
  if (money >= minimal_refill && money <= maximal_refill) {
    cash_operator.AddCash(money);
    refill_messenger_.ShowUserBalance(cash_operator.GetCash());
  } else {
    error_message_.NoticeAboutIncorrectSum();
  }
  utility_.IgnoreCinLine();
}
