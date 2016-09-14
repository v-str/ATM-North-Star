#ifndef SECONDARYCREDITOPERATIONS_H
#define SECONDARYCREDITOPERATIONS_H

#include "system_utility.h"
#include "user_identifier.h"
#include "user_input.h"
#include "credit_messenger.h"

class SecondaryCreditOperations {
 public:
  bool RepealACredit(UserIdentifier &user_identifier) const;

 private:
  UserInput user_input_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;

};

#endif  // SECONDARYCREDITOPERATIONS_H
