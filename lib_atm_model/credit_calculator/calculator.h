#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
 public:
  Calculator();

  void CalculateCredit(int credit_sum, double credit_interest_rate,
                       int amount_of_months);

  double MonthlyPayment() const;

 private:
  void CalculateMonthlyPayment();

  void CalculateMaturityInYears();
  void CalculatePercentsCoefficient();

  double PaymentFormulaNumerator();
  double PaymentFormulaDenominator();

  void Reset();

  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_months_;

  double monthly_payment_;
  double maturiry_in_years_;
  double percent_coefficient_;

  static const int kMonthsPerYear = 12;
};

#endif  // CALCULATOR_H
