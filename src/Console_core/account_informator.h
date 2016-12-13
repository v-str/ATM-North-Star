#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include "cash_operator.h"
#include "information_screen.h"
#include "user_identifier.h"
#include "console_editor.h"

class AccountInformator {
 public:
  void DisplayAccountInformation(UserIdentifier &user_identifier,
                                 CashOperator &cash_operator);

 private:
  InformationScreen screen_;
  ConsoleEditor console_editor_;
};

#endif  // ACCOUNT_INFORMATOR_H
