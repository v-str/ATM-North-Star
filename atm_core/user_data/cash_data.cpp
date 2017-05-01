#include "cash_data.h"

CashData::CashData() : cash_(0.0) {}

CashData::CashData(double cash) : cash_(cash) {}

void CashData::SetCash(double cash) { cash_ = cash; }

void CashData::AddCash(double cash) { cash_ += cash; }

void CashData::WithdrawCash(double cash) { cash_ -= cash; }

double CashData::GetCash() const { return cash_; }
