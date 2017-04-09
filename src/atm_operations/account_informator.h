#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include "console_editor.h"
#include "information_screen.h"
#include "atm_user.h"

class AccountInformator {
 public:
  void DisplayAccountInformationFor(AtmUser *atm_user);

 private:
  InformationScreen screen_;
  ConsoleEditor console_editor_;
};

#endif  // ACCOUNT_INFORMATOR_H
