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
  double PaymentFormulaNumerator();
  double PaymentFormulaDenominator();
  void Reset();

  double Y;
  int D;
  int n;
  double i;

  static const int m = 12;
  static const int one = 1;
};

#endif  // CALCULATOR_H
