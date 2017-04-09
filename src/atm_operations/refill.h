#ifndef REFILL_H
#define REFILL_H

#include <iostream>

#include "atm_user.h"
#include "console_editor.h"
#include "refill_messenger.h"
#include "user_input.h"
#include "notice_messenger.h"

class Refill {
 public:
  void StartRefillOperationFor(AtmUser *atm_user);

 private:
  static const int kNull = 0;
  static const int minimal_refill = 10;
  static const int maximal_refill = 50000;

  RefillMessenger refill_messenger_;
  NoticeMessenger notice_messenger_;
  UserInput user_input_;
  ConsoleEditor console_editor_;
};

#endif  // REFILL_H
