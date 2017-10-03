#ifndef CALCULATOR_DATA_HANDLER_H
#define CALCULATOR_DATA_HANDLER_H

#include <string>

#include <credit_data_bounder.h>

class CalculatorDataHandler {
 public:
  void HandleCreditData(int credit_sum, double credit_interest_rate,
                        int amount_of_credit_months);

  bool IsCalculationDataValid() const;

  int CreditSum() const;
  double InterestRate() const;
  int AmountOfMonth() const;

 private:
  void ResetData();
  void PerformValuesComparing();

  template <typename T>
  bool IsValueValid(const T& value, const T& upper_bound, const T& lower_bound,
                    const std::string& value_text_name) const;

  CreditDataBounder credit_data_bounder_;

  bool is_credit_ok_;
  bool is_interest_rate_ok_;
  bool is_amount_of_credit_months_ok;

  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_credit_months_;
};

#endif  // CALCULATOR_DATA_HANDLER_H
