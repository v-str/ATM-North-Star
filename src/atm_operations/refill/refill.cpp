#include "refill.h"

static const int kNull = 0;
static const int minimal_refill = 10;
static const int maximal_refill = 50000;

void Refill::StartRefillOperation(CashOperator &cash_operator) {
  refill_messenger_.ShowNotifyAboutCash();
  int money = kNull;
  cin >> money;
  if (money >= minimal_refill && money <= maximal_refill) {
    cash_operator.AddCash(money);
    refill_messenger_.ShowUserBalance(cash_operator.GetCash());
  } else {
    error_message_.NoticeAboutIncorrectSum();
  }
  utility_.IgnoreCinLine();
}
