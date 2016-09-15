#include "cash_operator.h"

void CashOperator::AddCash(UserIdentifier &user_identifier_, int sum_of_cash) {
  int total_cash = user_identifier_.GetCash() + sum_of_cash;
  user_identifier_.SetCash(total_cash);
}
