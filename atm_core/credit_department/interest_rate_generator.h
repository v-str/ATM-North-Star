#ifndef INTEREST_RATE_GENERATOR_H
#define INTEREST_RATE_GENERATOR_H

class InterestRateGenerator {
 public:
  static double GetInterestRate(double cash);

 private:
  static double GenerateInterestRate(int cash);

  static double kMinimalCash_;
  static double kMaximalCash_;

  static double kMinimalRate_;
  static double kMaximalRate_;
};

#endif  // INTEREST_RATE_GENERATOR_H
