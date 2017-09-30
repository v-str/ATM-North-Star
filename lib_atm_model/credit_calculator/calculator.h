#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>

#include <credit_payments_generator.h>

class Calculator {
 public:
  void CalculateCredit(int credit_sum,
                       double credit_interest_rate,
                       int amount_of_months);

  int AmountOfMonths() const;
  double MonthlyPayment() const;

  std::vector<std::string> SumOfOwedCredit() const;
  std::vector<std::string> SumOfInterestCharges() const;
  std::vector<std::string> SumOfMainDebtPayments() const;

 private:
  void CalculateMonthlyPayment();
  double PaymentFormulaNumerator();
  double PaymentFormulaDenominator();
  void Reset();

  static double kY;
  static int kD;
  static int kN;
  static double kI;

  CreditPaymentsGenerator credit_payments_generator_;

  static const int kM = 12;
  static const int kOne = 1;
};

#endif  // CALCULATOR_H
