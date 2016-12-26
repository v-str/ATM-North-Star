#include "credit.h"

void Credit::GiveCreditByMode(AtmUser *atm_user,
                              const string &user_login,
                              int maximal_sum_of_credit, int credit_mode) const {
  int amount_of_credit = secondary_credit_operation_.GetAmountCreditByMode(
      maximal_sum_of_credit, credit_mode);

  int amount_of_months = secondary_credit_operation_.GetAmountCreditMonths();

  credit_offer_.SuggestACredit(atm_user, user_login,
                                      amount_of_credit, amount_of_months);
}
