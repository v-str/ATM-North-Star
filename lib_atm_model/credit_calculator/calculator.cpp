#include <calculator.h>

Calculator::Calculator()
    : credit_sum_(0),
      credit_interest_rate_(0.0),
      amount_of_months_(0),
      mounthly_payment_(0.0),
      maturiry_in_years_(0.0) {}

void Calculator::CalculateCredit(int credit_sum, double credit_interest_rate,
                                 int amount_of_months) {
  credit_sum_ = credit_sum;
  credit_interest_rate_ = credit_interest_rate;
  amount_of_months_ = amount_of_months;
}

void Calculator::CalculateMonthlyPayment() { CalculateMaturityInYears(); }

void Calculator::CalculateMaturityInYears() {
  maturiry_in_years_ = amount_of_months_ / kMonthsPerYear;
}
