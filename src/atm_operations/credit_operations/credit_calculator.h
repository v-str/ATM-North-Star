#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

class CreditCalculator {
 public:
  int CalculateMaxCreditSum(int cash);

  void SetCreditSum(int credit_sum);
  void SetCreditTerm(int months);

  void CalculateCredit();

 private:
  int multiplier_ = 15;
  int max_credit_sum_ = 0;
  int credit_sum_ = 0;
  int credit_term_ = 0;
  double interest_rate_ = 14.0;
};

#endif  // CREDIT_CALCULATOR_H
