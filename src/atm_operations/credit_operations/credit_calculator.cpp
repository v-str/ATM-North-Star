#include "credit_calculator.h"

int CreditCalculator::CalculateMaxCreditSum(int cash) {
  return max_credit_sum_ = multiplier_ * cash;
}
