#ifndef INPUT_DATA_VALIDATOR_H
#define INPUT_DATA_VALIDATOR_H

#include <string>

class InputDataValidator {
 public:
  static bool IsLoginLengthCorrect(const std::string& login);
  static bool IsPasswordLengthCorrect(const std::string& login);
  static bool IsRefillingCorrect(int refill_sum);
  static bool IsWithdrawalCorrect(int withdrawal_sum);

 private:
  static bool IsIntegerValue(double value);

  static constexpr int k_login_max_length_ = 35;
  static constexpr int k_login_min_length_ = 4;
  static constexpr int k_password_length_ = 4;
  static constexpr double k_null_ = 0.0;

  static constexpr int k_min_refill_sum_ = 10;
  static constexpr int k_max_refill_sum_ = 50000;

  static constexpr int k_min_withdrawal_sum_ = 10;
  static constexpr int k_max_withdrawal_sum_ = 10000;
};

#endif  // INPUT_DATA_VALIDATOR_H
