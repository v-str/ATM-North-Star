#ifndef CREDIT_PAYMENTS_GENERATOR_H
#define CREDIT_PAYMENTS_GENERATOR_H

#include <vector>

class CreditPaymentsGenerator {
 public:
  CreditPaymentsGenerator();

  void GenerateCreditPayments(int credit_sum,
                              double monthly_payment,
                              double percentage_coefficient,
                              int credit_term_months);

  std::vector<double> SumOfOwedCredit() const;
  std::vector<double> SumOfInterestChares() const;
  std::vector<double> SumOfMainDebtPayments() const;

 private:
  void ConstructCreditTable();

  double credit_sum_;
  double monthly_payment_;
  double percentage_coefficient_;
  int credit_term_months_;

  double interest_charge_;
  double main_debp_payment_;

  std::vector<double> sum_of_owed_credit_;
  std::vector<double> sum_of_interest_charges_;
  std::vector<double> sum_of_main_debt_payments_;

  static const int kMonthsPerYear = 12;
};

#endif  // CREDIT_PAYMENTS_GENERATOR_H
