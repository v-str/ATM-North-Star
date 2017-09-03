#ifndef CASH_OPERATION_VALIDATOR_H
#define CASH_OPERATION_VALIDATOR_H

#include <string>

class CashOperationValidator {
 public:
  static bool IsRefillingCorrect(int refill_sum);
  static bool IsWithdrawalCorrect(int withdrawal_sum);

 private:
  static constexpr double kNull = 0.0;
  static constexpr int kMinimalRefillSum = 10;
  static constexpr int kMaximalRefillSum = 50000;
  static constexpr int kMinimalWithdrawalSum = 10;
  static constexpr int kMaximalWithdrawalSum = 10000;
};

#endif  // CASH_OPERATION_VALIDATOR_H
