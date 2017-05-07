#include "refill.h"

#include <atm_user.h>

void Refill::RefillCash(AtmUser& user, int refill_sum) {
  user.AddCash(refill_sum);
}
