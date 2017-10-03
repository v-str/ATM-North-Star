#include <credit_data_bounder.h>

CreditDataBounder::CreditDataBounder()
    : lower_credit_sum_bound_(10000),
      upper_credit_sum_bound_(500000),
      lower_interest_rate_bound_(5.0),
      upper_interest_rate_bound_(50.0),
      lower_amount_of_month_bound_(1),
      upper_ampunt_of_month_bound_(60) {}

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
