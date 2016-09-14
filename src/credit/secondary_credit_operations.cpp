#include "secondary_credit_operations.h"

bool SecondaryCreditOperations::RepealACredit(
    UserIdentifier &user_identifier) const {
  user_identifier.AssignACredit(0);
  user_identifier.AssignAMonthlyPayment(0.0);
  credit_messenger_.ShowRepealACreadit();
  return user_input_.SuggestUserToExit();
}
