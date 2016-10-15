#ifndef REFILL_H
#define REFILL_H

#include <iostream>
#include "cash_operator.h"
#include "refill_messenger.h"
#include "system_utility.h"
#include "user_input.h"

class Refill {
 public:
  void StartRefillOperation(CashOperator &cash_operator);
  void soon();

 private:
  RefillMessenger refill_messenger_;
  Notifier error_message_;
  SystemUtility utility_;
  UserInput user_input_;
};

#endif  // REFILL_H
