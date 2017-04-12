#include "credit_department.h"

int CreditDepartment::ResultOfUserCheck(const AtmUser& user) const {
  return checker_.GetResultOfUserCheck(user);
}

int CreditDepartment::MaxCreditSum(int cash) {
  return calculator_.CalculateMaxCreditSum(cash);
}

void CreditDepartment::SetCreditSum(int credit_sum) {
  credit_data_.credit_sum_ = credit_sum;
  calculator_.SetUserCreditSum(credit_sum);
}
