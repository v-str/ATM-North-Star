#ifndef CREDIT_TABLE_H
#define CREDIT_TABLE_H

#include <vector>

class CreditTable {
 public:
  CreditTable();

  void CalculateCreditTable(int credit_sum, double monthly_payment,
                            double percentage_coefficient,
                            int credit_term_months);

 private:
  void ConstructCreditTable();

  int credit_sum_;
  double monthly_payment_;
  double percentage_coefficient_;
  int credit_term_months_;

  double percentages_payment_per_month_;
  double payment_per_month_;

  std::vector<double> balance_owed_;
  std::vector<double> percentages_debt_;
  std::vector<double> principal_debt_;

  static const int kMonthsPerYear = 12;
};

#endif  // CREDIT_TABLE_H
