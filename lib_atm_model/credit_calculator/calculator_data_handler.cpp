#include <calculator_data_handler.h>

#include <calculator_error_informer.h>

void CalculatorDataHandler::HandleCreditData(int credit_sum,
                                             double credit_interest_rate,
                                             int amount_of_credit_months) {
  ResetData();
  credit_sum_ = credit_sum;
  credit_interest_rate_ = credit_interest_rate;
  amount_of_credit_months_ = amount_of_credit_months;
  PerformValuesComparing();
}

bool CalculatorDataHandler::IsCalculationDataValid() const {
  if (is_credit_ok_ && is_interest_rate_ok_ && is_amount_of_credit_months_ok) {
    return true;
  }
  return false;
}

int CalculatorDataHandler::CreditSum() const { return credit_sum_; }

double CalculatorDataHandler::InterestRate() const {
  return credit_interest_rate_;
}

int CalculatorDataHandler::AmountOfMonth() const {
  return amount_of_credit_months_;
}

void CalculatorDataHandler::ResetData() {
  CalculatorErrorInformer::ResetErrorList();
  is_credit_ok_ = false;
  is_interest_rate_ok_ = false;
  is_amount_of_credit_months_ok = false;
}

void CalculatorDataHandler::PerformValuesComparing() {
  is_credit_ok_ =
      IsValueValid(credit_sum_, credit_data_bounder_.LowerCreditSum(),
                   credit_data_bounder_.UpperCreditSum(), "Credit sum");
  is_interest_rate_ok_ = IsValueValid(
      credit_interest_rate_, credit_data_bounder_.LowerInterestRate(),
      credit_data_bounder_.UpperInterestRate(), "Credit interest rate");
  is_amount_of_credit_months_ok = IsValueValid(
      amount_of_credit_months_, credit_data_bounder_.LowerAmountOfMonth(),
      credit_data_bounder_.UpperAmountOfMonth(), "Amount of months");
}

template <typename T>
bool CalculatorDataHandler::IsValueValid(
    const T &value, const T &upper_bound, const T &lower_bound,
    const std::string &value_text_name) const {
  if (value >= upper_bound && value <= lower_bound) {
    return true;
  } else {
    CalculatorErrorInformer::AddErrorText(value_text_name +
                                          " was inputted incorrectly");
    return false;
  }
}
