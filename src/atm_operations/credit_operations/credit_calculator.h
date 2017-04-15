#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <utility>
#include <vector>

class CreditCalculator {
 public:
  int CalculateMaxCreditSum(int cash);

  void SetCreditSum(int credit_sum);
  void SetCreditTerm(int months);

  void CalculateCredit();

 private:
  double AnnuityMonthlyPayment();

  int multiplier_ = 15;
  int max_credit_sum_ = 0;
  int credit_sum_ = 0;
  int credit_term_ = 0;
  double interest_rate_ = 14.0;

  std::vector<std::pair<double, double>> payments_;
};

#endif  // CREDIT_CALCULATOR_H
