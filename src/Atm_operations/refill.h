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

 private:
  static const int kNull = 0;
  static const int minimal_refill = 10;
  static const int maximal_refill = 50000;

  RefillMessenger refill_messenger_;
  NoticeMessenger notice_messenger_;
  SystemUtility utility_;
  UserInput user_input_;
};

#endif  // REFILL_H
