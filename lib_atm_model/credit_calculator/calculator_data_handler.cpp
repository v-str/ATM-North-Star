#include <calculator_data_handler.h>

#include <calculator_data_transformer.h>

CalculatorDataHandler::HandleData(int credit_sum, double credit_interest_rate,
                                  int amount_of_credit_months) {
  credit_sum_ = credit_sum;
  credit_interest_rate_ = credit_interest_rate;
  amount_of_credit_months_ = amount_of_credit_months;
}

bool CalculatorDataHandler::IsCreditDataValid() const {
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
