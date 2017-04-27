#ifndef INTEREST_RATE_GENERATOR_H
#define INTEREST_RATE_GENERATOR_H

class InterestRateGenerator {
 public:
  static double GetInterestRate(double cash);
  static double GenerateInterestRate(int cash);

 private:
  static int kMinimalCash_;
  static int kMaximalCash_;

  static double kMinimalRate_;
  static double kMaximalRate_;
};

#endif  // INTEREST_RATE_GENERATOR_H
