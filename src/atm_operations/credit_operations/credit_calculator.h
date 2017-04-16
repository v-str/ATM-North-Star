#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <utility>
#include <vector>

#include "credit_data.h"

class CreditCalculator {
 public:
  int CalculateMaxCreditSum(int cash, int multiplier);

  void SetCreditSum(CreditData* credit_data, int credit_sum);
  void SetCreditTerm(CreditData* credit_data, int months);

  void CalculateCredit(CreditData* credit_data);

 private:
  double AnnuityMonthlyPayment(const CreditData& credit_data);

  std::vector<std::pair<double, double>> payments_;
};

#endif  // CREDIT_CALCULATOR_H
