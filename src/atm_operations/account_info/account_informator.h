#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include "cash_operator.h"
#include "user_identifier.h"
#include "information_screen.h"


class AccountInformator {
 public:
  void DisplayAccountInformation(UserIdentifier &user_identifier,
                                 CashOperator &cash_operator);

 private:
  InformationScreen screen_;
};

#endif  // ACCOUNT_INFORMATOR_H
