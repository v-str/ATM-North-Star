#include <credit_data_bounder.h>

CreditDataBounder::CreditDataBounder()
    : lower_credit_sum_bound_(10000),
      upper_credit_sum_bound_(500000),
      lower_interest_rate_bound_(5.0),
      upper_interest_rate_bound_(60.0),
      lower_amount_of_month_bound_(1),
      upper_ampunt_of_month_bound_(60) {}

void CreditDataBounder::SetCreditSumBound(int lower_credit_sum_bound,
                                          int upper_credit_sum_bound) {
  lower_credit_sum_bound_ = lower_credit_sum_bound;
  upper_credit_sum_bound_ = upper_credit_sum_bound;
}

void CreditDataBounder::SetIntersetRateBound(double lower_interest_rate_bound,
                                             double upper_interest_rate_bound) {
  lower_interest_rate_bound_ = lower_interest_rate_bound;
  upper_interest_rate_bound_ = upper_interest_rate_bound;
}

void CreditDataBounder::SetAmountOfMonthBound(
    double lower_ampunt_of_month_bound, double upper_ampunt_of_month_bound) {
  lower_amount_of_month_bound_ = lower_ampunt_of_month_bound;
  upper_ampunt_of_month_bound_ = upper_ampunt_of_month_bound;
}

int CreditDataBounder::LowerCreditSum() const {
  return lower_credit_sum_bound_;
}

int CreditDataBounder::UpperCreditSum() const {
  return upper_credit_sum_bound_;
}

double CreditDataBounder::LowerInterestRate() const {
  return lower_interest_rate_bound_;
}

double CreditDataBounder::UpperInterestRate() const {
  return upper_interest_rate_bound_;
}

int CreditDataBounder::LowerAmountOfMonth() const {
  return lower_amount_of_month_bound_;
}

int CreditDataBounder::UpperAmountOfMonth() const {
  return upper_ampunt_of_month_bound_;
}
