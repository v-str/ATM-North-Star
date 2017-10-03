#include <withdrawal.h>

#include <atm_user.h>

void Withdrawal::WithdrawCashFrom(AtmUser* user, int sum_of_withdrawal) {
  user->WithdrawCash(sum_of_withdrawal);
}
