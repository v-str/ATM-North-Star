#ifndef INPUT_DATA_VALIDATOR_H
#define INPUT_DATA_VALIDATOR_H

#include <string>

class InputDataValidator {
 public:
  static bool IsRefillingCorrect(int refill_sum);
  static bool IsWithdrawalCorrect(int withdrawal_sum);

 private:
  static bool IsIntegerValue(double value);

  static constexpr double k_null_ = 0.0;

  static constexpr int k_min_refill_sum_ = 10;
  static constexpr int k_max_refill_sum_ = 50000;

  static constexpr int k_min_withdrawal_sum_ = 10;
  static constexpr int k_max_withdrawal_sum_ = 10000;
};

#endif  // INPUT_DATA_VALIDATOR_H
