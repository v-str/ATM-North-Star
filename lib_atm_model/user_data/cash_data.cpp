#include <cash_data.h>

CashData::CashData() : cash_(0.0) {}

void CashData::SetCash(double cash) { cash_ = cash; }

void CashData::AddCash(double cash) { cash_ += cash; }

void CashData::WithdrawCash(double cash) { cash_ -= cash; }

double CashData::Cash() const { return cash_; }
