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
  void CalculatePercentsCoefficient();

  double PaymentFormulaNumerator();
  double PaymentFormulaDenominator();

  void Reset();

  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_months_;

  double monthly_payment_;
  double percent_coefficient_;

  static const int kMonthsPerYear = 12;
  static const int kOne = 1;
};

#endif  // CALCULATOR_H
