#include "credit_calculator.h"

int CreditCalculator::CalculateMaxCreditSum(int cash) {
  return max_credit_sum_ = multiplier_ * cash;
}

void CreditCalculator::SetUserCreditSum(int credit_sum) {
  user_credit_sum_ = credit_sum;
}
