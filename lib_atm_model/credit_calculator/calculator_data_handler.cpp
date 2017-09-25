#include <calculator_data_handler.h>

void CalculatorDataHandler::HandleData(int credit_sum,
                                       double credit_interest_rate,
                                       int amount_of_credit_months) {
  ResetData();
  credit_sum_ = credit_sum;
  credit_interest_rate_ = credit_interest_rate;
  amount_of_credit_months_ = amount_of_credit_months;
  is_credit_ok_ = IsCreditSumValid();
  is_interest_rate_ok_ = IsCreditInterestRateValid();
  is_amount_of_credit_months_ok = IsAmountOfCreditValid();
}

bool CalculatorDataHandler::IsCalculationDataValid() const {
  if (is_credit_ok_ && is_interest_rate_ok_ && is_amount_of_credit_months_ok) {
    return true;
  }
  return false;
}

bool CalculatorDataHandler::IsCreditSumValid() const {
  if (credit_sum_ >= credit_data_bounder_.LowerCreditSum() &&
      credit_sum_ <= credit_data_bounder_.UpperCreditSum()) {
    return true;
  }
  return false;
}

bool CalculatorDataHandler::IsCreditInterestRateValid() const {
  if (credit_interest_rate_ >= credit_data_bounder_.LowerInterestRate() &&
      credit_interest_rate_ <= credit_data_bounder_.UpperInterestRate()) {
    return true;
  }
  return false;
}

bool CalculatorDataHandler::IsAmountOfCreditValid() const {
  if (amount_of_credit_months_ >= credit_data_bounder_.LowerAmountOfMonth() &&
      amount_of_credit_months_ <= credit_data_bounder_.UpperAmountOfMonth()) {
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
  is_credit_ok_ = false;
  is_interest_rate_ok_ = false;
  is_amount_of_credit_months_ok = false;
}
