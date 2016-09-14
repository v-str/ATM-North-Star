#ifndef SECONDARY_CREDIT_OPERATIONS_H
#define SECONDARY_CREDIT_OPERATIONS_H

#include "credit_messenger.h"
#include "system_utility.h"
#include "user_identifier.h"
#include "user_input.h"

class SecondaryCreditOperations {
 public:
  bool EnrollACredit(UserIdentifier &user_identifier, const int sum_of_credit,
                     const int pay_per_month) const;

  bool RepealACredit(UserIdentifier &user_identifier) const;

  int GetAmountOfCreditMonthsFromUser();

 private:
  UserInput user_input_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
};

#endif  // SECONDARY_CREDIT_OPERATIONS_H
