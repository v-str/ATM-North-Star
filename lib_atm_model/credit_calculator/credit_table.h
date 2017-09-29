#ifndef CREDIT_TABLE_H
#define CREDIT_TABLE_H

#include <vector>

class CreditTable {
 public:
  CreditTable();

  void CalculateCreditTable(int credit_sum,
                            double monthly_payment,
                            double percentage_coefficient,
                            int credit_term_months);

 private:
  void ConstructCreditTable();

  double credit_sum_;
  double monthly_payment_;
  double percentage_coefficient_;
  int credit_term_months_;

  double interest_charge_;
  double main_debp_payment_;

  std::vector<double> balance_owed_;
  std::vector<double> interest_charges_;
  std::vector<double> main_debt_payments_;

  static const int kMonthsPerYear = 12;
};

#endif  // CREDIT_TABLE_H
