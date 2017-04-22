#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <utility>
#include <vector>

#include "atm_user.h"
#include "credit_data.h"

class CreditCalculator {
 public:
  int CalculateMaxCreditSum(int cash, int multiplier);

  void SetCreditSum(CreditData* credit_data, int credit_sum);
  void SetCreditTerm(CreditData* credit_data, int months);

  void CalculateCredit(CreditData* credit_data);

 private:
  double AnnuityMonthlyPayment(const CreditData& credit_data);

  void FillCreditPaysheet(double annuity_credit_payment,
                          double total_overpayment);

  std::vector<std::pair<double, double>> paysheet_;
};

#endif  // CREDIT_CALCULATOR_H
