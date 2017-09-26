#include <calculator.h>

#include <math.h>

Calculator::Calculator()
    : credit_sum_(0),
      credit_interest_rate_(0.0),
      amount_of_months_(0),
      monthly_payment_(0.0),
      maturiry_in_years_(0.0),
      percent_coefficient_(0.0) {}

void Calculator::CalculateCredit(int credit_sum, double credit_interest_rate,
                                 int amount_of_months) {
  Reset();

  credit_sum_ = credit_sum;
  credit_interest_rate_ = credit_interest_rate;
  amount_of_months_ = amount_of_months;
}

double Calculator::MonthlyPayment() const { return monthly_payment_; }

void Calculator::CalculateMonthlyPayment() {
  CalculateMaturityInYears();
  CalculatePercentsCoefficient();
  monthly_payment_ = PaymentFormulaNumerator() / PaymentFormulaDenominator();
}

void Calculator::CalculateMaturityInYears() {
  maturiry_in_years_ = amount_of_months_ / kMonthsPerYear;
}

void Calculator::CalculatePercentsCoefficient() {
  percent_coefficient_ = credit_interest_rate_ / 100;
}

/// Formula for annuity credit payments
///
///               D * i / m
/// Y = ------------------------------
///       1 - 1 / ( 1 + i / m )^n*m
///
/// D - sum of credit
/// i - interest rate as coefficient (percents / 100%)
/// m - percentage payments per year equal 12 (12 month per year)
/// n - credit term in years
///

double Calculator::PaymentFormulaNumerator() {
  double numerator_calculation =
      credit_sum_ * (percent_coefficient_ / kMonthsPerYear);
  return numerator_calculation;
}

double Calculator::PaymentFormulaDenominator() {
  int one = 1;
  double denominator = one + (percent_coefficient_ / kMonthsPerYear);
  double result = one - 1 / pow(denominator, maturiry_in_years_);
  return result;
}

void Calculator::Reset() {
  credit_sum_ = 0;
  credit_interest_rate_ = 0.0;
  amount_of_months_ = 0;
  monthly_payment_ = 0.0;
  maturiry_in_years_ = 0.0;
  percent_coefficient_ = 0.0;
}
