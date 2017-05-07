#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include <information_screen.h>

class AtmUser;

class AccountInformator {
 public:
  void DisplayAccountInformationFor(AtmUser* atm_user);

 private:
  InformationScreen screen_;
};

#endif  // ACCOUNT_INFORMATOR_H
