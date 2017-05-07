#ifndef REFILL_H
#define REFILL_H

class AtmUser;

class Refill {
 public:
  static void RefillCash(AtmUser* user, int refill_sum);
};

#endif  // REFILL_H
