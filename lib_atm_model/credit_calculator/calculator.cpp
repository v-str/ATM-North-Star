#include <calculator.h>

#include <math.h>

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                     Annuity credit payment formula                       ///
///                                                                          ///
///                                D * i / m                                 ///
///                 Y = ------------------------------                       ///
///                       1 - 1 / ( 1 + i / m )^n*m                          ///
///                                                                          ///
///     D - sum of credit                                                    ///
///     i - interest rate as coefficient (percents / 100%)                   ///
///     m - percentage payments per year equal 12 (12 month per year)        ///
///     n - credit term in years                                             ///
///                                                                          ///
/// ////////////////////////////////////////////////////////////////////////////

Calculator::Calculator() : Y(0.0), D(0), n(0), i(0.0) {}

void Calculator::CalculateCredit(int credit_sum, double credit_interest_rate,
                                 int amount_of_months) {
  Reset();

  D = credit_sum;
  i = credit_interest_rate / 100;
  n = amount_of_months / m;

  CalculateMonthlyPayment();
}

double Calculator::MonthlyPayment() const { return Y; }

void Calculator::CalculateMonthlyPayment() {
  Y = PaymentFormulaNumerator() / PaymentFormulaDenominator();
}

double Calculator::PaymentFormulaNumerator() {
  double numerator_calculation = D * (i / m);
  return numerator_calculation;
}

double Calculator::PaymentFormulaDenominator() {
  double denominator = one + (i / m);
  double result = one - (one / pow(denominator, n));
  return result;
}

void Calculator::Reset() {
  Y = 0.0;
  D = 0;
  n = 0;
  i = 0.0;
}
