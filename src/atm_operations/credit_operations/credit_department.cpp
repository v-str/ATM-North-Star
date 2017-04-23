#include "credit_department.h"

int CreditDepartment::ResultOfUserCheck(const AtmUser& user) const {
  return checker_.GetResultOfUserCheck(user);
}

int CreditDepartment::MaxCreditSum(int cash) {
  return calculator_.CalculateMaxCreditSum(cash,
                                           credit_data_.CreditMultiplier());
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

int CreditDepartment::CreditSum() const { return credit_data_.CreditSum(); }

int CreditDepartment::CreditTerm() const { return credit_data_.CreditTerm(); }

double CreditDepartment::InterestRate() const {
  return credit_data_.InterestRate();
}
