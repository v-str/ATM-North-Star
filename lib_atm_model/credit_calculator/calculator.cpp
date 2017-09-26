#include <calculator.h>

Calculator::Calculator()
    : credit_sum_(0),
      credit_interest_rate_(0.0),
      amount_of_months_(0),
      mounthly_payment_(0.0),
      maturiry_in_years_(0.0),
      percent_coefficient_(0.0) {}

void Calculator::CalculateCredit(int credit_sum, double credit_interest_rate,
                                 int amount_of_months) {
  credit_sum_ = credit_sum;
  credit_interest_rate_ = credit_interest_rate;
  amount_of_months_ = amount_of_months;
}

void Calculator::CalculateMonthlyPayment() {
  CalculateMaturityInYears();
  CalculatePercentsCoefficient();
  // mounthly_payment_ = PaymentFormulaNumerator() /
  // PaymentFormulaDenominator();
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
}

double Calculator::PaymentFormulaDenominator() {}
