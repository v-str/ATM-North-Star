#include "credit_department.h"

int CreditDepartment::ResultOfUserCheck(const AtmUser& user) const {
  return checker_.GetResultOfUserCheck(user);
}

int CreditDepartment::MaxCreditSum(int cash) {
  return calculator_.CalculateMaxCreditSum(cash, credit_data_.Multiplier());
}

void CreditDepartment::SetCreditSum(int credit_sum) {
  calculator_.SetCreditSum(&credit_data_, credit_sum);
}

void CreditDepartment::SetCreditTerm(int months) {
  calculator_.SetCreditTerm(&credit_data_, months);
}

void CreditDepartment::CalculateCredit() {
  calculator_.CalculateCredit(&credit_data_);
}
