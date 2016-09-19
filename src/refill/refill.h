#ifndef REFILL_H
#define REFILL_H

#include <iostream>
#include "cash_operator.h"
#include "notifications_about_operations/notice_about_error.h"
#include "refill_messenger.h"
#include "system_utility.h"
#include "user_input.h"
#include "user_messenger.h"

class Refill {
 public:
  bool StartRefillOperation(CashOperator &cash_operator);

 private:
  RefillMessenger refill_messenger_;
  NoticeAboutError error_message_;
  SystemUtility utility_;
  UserInput user_input_;
};

#endif  // REFILL_H
