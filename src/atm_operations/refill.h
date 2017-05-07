#ifndef REFILL_H
#define REFILL_H

#include <iostream>

#include <notice_messenger.h>
#include <refill_messenger.h>
#include <user_input.h>

class AtmUser;

class Refill {
 public:
  void StartRefillOperationFor(AtmUser* atm_user);

 private:
  static constexpr int kNull = 0;
  static constexpr int minimal_refill = 10;
  static constexpr int maximal_refill = 50000;

  RefillMessenger refill_messenger_;
  NoticeMessenger notice_messenger_;
  UserInput user_input_;
};

#endif  // REFILL_H
