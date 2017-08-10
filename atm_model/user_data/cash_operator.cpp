#include "cash_operator.h"

void CashOperator::SetCash(int cash) { cash_ = cash; }

int CashOperator::Cash() const { return cash_; }

int CashOperator::WithdrawCash(int cash) { return cash_ -= cash; }

void CashOperator::AddCash(int cash) { cash_ += cash; }
