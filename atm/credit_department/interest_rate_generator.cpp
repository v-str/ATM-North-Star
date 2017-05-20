#include "interest_rate_generator.h"

double InterestRateGenerator::maximal_rate_ = 14.0;
double InterestRateGenerator::minimal_rate_ = 5.0;
double InterestRateGenerator::minimal_cash_ = 1000.0;
double InterestRateGenerator::maximal_cash_ = 20000.0;

double InterestRateGenerator::GetInterestRate(double cash) {
  if (cash == minimal_cash_) {
    return maximal_rate_;
  } else if (cash >= maximal_cash_) {
    return minimal_rate_;
  } else {
    return GenerateInterestRate(cash);
  }
}

double InterestRateGenerator::GenerateInterestRate(int cash) {
  double interest_rate = (cash - minimal_cash_) / minimal_cash_;
  return interest_rate;
}
