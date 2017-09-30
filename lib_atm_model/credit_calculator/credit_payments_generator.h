#ifndef CREDIT_PAYMENTS_GENERATOR_H
#define CREDIT_PAYMENTS_GENERATOR_H

#include <string>
#include <vector>

class CreditPaymentsGenerator {
 public:
  CreditPaymentsGenerator();

  void GenerateCreditPayments(int credit_sum,
                              double monthly_payment,
                              double percentage_coefficient);

  std::vector<std::string> SumOfOwedCredit() const;
  std::vector<std::string> SumOfInterestCharges() const;
  std::vector<std::string> SumOfMainDebtPayments() const;

  std::string TotalMonthlyPayment() const;
  std::string TotalInterestCharges() const;
  std::string TotalMainDebtPayment() const;

 private:
  void CalculatePaymentTable();
  void CalculateLastPayment();
  void FillPaymentContainers(double sum_of_owed_credit,
                             double sum_of_interest_charges,
                             double sum_of_main_debt_payments);

  std::string ConvertToString(double value) const;

  void Reset();

  double credit_sum_;
  double monthly_payment_;
  double percentage_coefficient_;
  double interest_charge_;
  double main_debp_payment_;

  double total_monthly_payment_;
  double total_interest_charges_;
  double total_main_debt_payment_;

  std::vector<std::string> sum_of_owed_credit_;
  std::vector<std::string> sum_of_interest_charges_;
  std::vector<std::string> sum_of_main_debt_payments_;

  static const int kMonthsPerYear = 12;
};

#endif  // CREDIT_PAYMENTS_GENERATOR_H
