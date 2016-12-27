#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include "information_screen.h"
#include "output_configuration/console_editor.h"
#include "user_data/atm_user.h"

class AccountInformator {
 public:
  void DisplayAccountInformation(AtmUser *atm_user);

 private:
  InformationScreen screen_;
  ConsoleEditor console_editor_;
};

#endif  // ACCOUNT_INFORMATOR_H
