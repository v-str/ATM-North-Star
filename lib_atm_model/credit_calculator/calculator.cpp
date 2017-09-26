#include <calculator.h>

#include <math.h>

//                     Annuity credit payment formula
//
//                                D * i / m
//                 Y = ------------------------------
//                       1 - 1 / ( 1 + i / m )^n*m
//
//     D - sum of credit
//     i - interest rate as coefficient (percents / 100%)
//     m - percentage payments per year equal 12 (12 month per year)
//     n - credit term in years
//

double Calculator::kY = 0.0;
int Calculator::kD = 0;
int Calculator::kn = 0;
double Calculator::ki = 0.0;

void Calculator::CalculateCredit(int credit_sum, double credit_interest_rate,
                                 int amount_of_months) {
  Reset();

  kD = credit_sum;
  ki = credit_interest_rate / 100;
  kn = amount_of_months;

  CalculateMonthlyPayment();
}

double Calculator::MonthlyPayment() { return kY; }

void Calculator::CalculateMonthlyPayment() {
  kY = PaymentFormulaNumerator() / PaymentFormulaDenominator();
}

double Calculator::PaymentFormulaNumerator() {
  double numerator_calculation = kD * (ki / kM);
  return numerator_calculation;
}

double Calculator::PaymentFormulaDenominator() {
  double denominator = kOne + (ki / kM);
  double result = kOne - (kOne / pow(denominator, kn));
  return result;
}

void Calculator::Reset() {
  kY = 0.0;
  kD = 0;
  kn = 0;
  ki = 0.0;
}
