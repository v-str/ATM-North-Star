#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <credit_payments_generator.h>

class Calculator {
 public:
  static void CalculateCredit(int credit_sum,
                              double credit_interest_rate,
                              int amount_of_months);

  static double MonthlyPayment();

 private:
  static void CalculateMonthlyPayment();
  static double PaymentFormulaNumerator();
  static double PaymentFormulaDenominator();
  static void Reset();

  static double kY;
  static int kD;
  static int kN;
  static double kI;

  static CreditPaymentsGenerator credit_payments_generator_;

  static const int kM = 12;
  static const int kOne = 1;
};

#endif  // CALCULATOR_H
