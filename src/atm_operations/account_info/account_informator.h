#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include "account_messenger.h"
#include "cash_operator.h"
#include "user_identifier.h"

class AccountInformator {
 public:
  void DisplayAccountInformation(UserIdentifier &user_identifier,
                                 CashOperator &cash_operator);

 private:
  AccountMessenger account_messenger_;
};

#endif  // ACCOUNT_INFORMATOR_H
