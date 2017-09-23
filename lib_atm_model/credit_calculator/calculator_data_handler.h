#ifndef CALCULATOR_DATA_HANDLER_H
#define CALCULATOR_DATA_HANDLER_H

#include <string>

#include <credit_data_bounder.h>

class CalculatorDataHandler {
 public:
  HandleData(const std::string credit_sum,
             const std::string credit_interest_rate,
             const std::string amount_of_credit_months);

 private:
  CreditDataBounder credit_data_bounder_;

  int credit_sum_;
  double interest_rate_;
  int amount_of_credit_months_;
};

#endif  // CALCULATOR_DATA_HANDLER_H
