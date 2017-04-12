#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

class CreditCalculator {
 public:
  int CalculateMaxCreditSum(int cash);

 private:
  int multiplier_ = 15;
  int max_credit_sum_ = 0;
};

#endif  // CREDIT_CALCULATOR_H
