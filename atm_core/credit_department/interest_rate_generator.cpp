#include "interest_rate_generator.h"

double InterestRateGenerator::kMaximalRate_ = 14.0;
double InterestRateGenerator::kMinimalRate_ = 5.0;
int InterestRateGenerator::kMinimalCash_ = 1000;
int InterestRateGenerator::kMaximalCash_ = 20000;

double InterestRateGenerator::GetInterestRate(double cash) {
  if (cash == kMinimalCash_) {
    return kMaximalRate_;
  } else if (cash >= kMaximalCash_) {
    return kMinimalRate_;
  } else {
    return GenerateInterestRate(cash);
  }
}

double InterestRateGenerator::GenerateInterestRate(int cash) {
  double interest_rate = (cash - kMinimalCash_) / kMinimalCash_;
  return interest_rate;
}
