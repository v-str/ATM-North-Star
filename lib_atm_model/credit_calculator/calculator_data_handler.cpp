#include <calculator_data_handler.h>

#include <calculator_data_transformer.h>

CalculatorDataHandler::HandleData(const std::string &credit_sum,
                                  const std::string &credit_interest_rate,
                                  const std::string &amount_of_credit_months) {
  credit_sum_ = CalculatorDataTransformer::TransformIntegerData(credit_sum);
  credit_interest_rate_ =
      CalculatorDataTransformer::TransformFractionalData(credit_interest_rate);
  amount_of_credit_months_ =
      CalculatorDataTransformer::TransformIntegerData(amount_of_credit_months);
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
