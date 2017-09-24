#ifndef CALCULATOR_DATA_HANDLER_H
#define CALCULATOR_DATA_HANDLER_H

#include <credit_data_bounder.h>

class CalculatorDataHandler {
 public:
  HandleData(int credit_sum, double credit_interest_rate,
             int amount_of_credit_months);

  bool IsCreditDataValid() const;
  bool IsCreditInterestRateValid() const;
  bool IsAmountOfCreditValid() const;

  int CreditSum() const;
  double InterestRate() const;
  int AmountOfMonth() const;

 private:
  CreditDataBounder credit_data_bounder_;

  bool is_credit_ok_;
  bool is_interest_rate_ok_;
  bool is_amount_of_credit_months_ok;

  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_credit_months_;
};

#endif  // CALCULATOR_DATA_HANDLER_H
