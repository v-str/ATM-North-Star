#include <calculator.h>

#include <math.h>

//                     Annuity credit payment formula
//
//                                D * I / M
//                 Y = ------------------------------
//                       1 - 1 / ( 1 + I / M )^N*M
//
//     D - sum of credit
//     i - interest rate as coefficient (percents / 100%)
//     m - percentage payments per year equal 12 (12 month per year)
//     n - credit term in years
//

double Calculator::kY = 0.0;
int Calculator::kD = 0;
int Calculator::kN = 0;
double Calculator::kI = 0.0;

void Calculator::CalculateCredit(int credit_sum, double credit_interest_rate,
                                 int amount_of_months) {
  Reset();

  kD = credit_sum;
  kI = credit_interest_rate / 100;
  kN = amount_of_months;

  CalculateMonthlyPayment();
}

double Calculator::MonthlyPayment() { return kY; }

void Calculator::CalculateMonthlyPayment() {
  kY = PaymentFormulaNumerator() / PaymentFormulaDenominator();
}

double Calculator::PaymentFormulaNumerator() {
  double numerator_calculation = kD * (kI / kM);
  return numerator_calculation;
}

double Calculator::PaymentFormulaDenominator() {
  double denominator = kOne + (kI / kM);
  double result = kOne - (kOne / pow(denominator, kN));
  return result;
}

void Calculator::Reset() {
  kY = 0.0;
  kD = 0;
  kN = 0;
  kI = 0.0;
}
