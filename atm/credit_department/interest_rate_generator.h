#ifndef INTEREST_RATE_GENERATOR_H
#define INTEREST_RATE_GENERATOR_H

class InterestRateGenerator {
 public:
  static double GetInterestRate(double cash);

 private:
  static double GenerateInterestRate(int cash);

  static double minimal_cash_;
  static double maximal_cash_;

  static double minimal_rate_;
  static double maximal_rate_;
};

#endif  // INTEREST_RATE_GENERATOR_H
