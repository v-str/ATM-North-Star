#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include <string>

#include "cash_operator.h"
#include "system_utility.h"
#include "user_identifier.h"

using std::cout;
using std::cin;

class AccountInformator {
 public:
  void DisplayAccountInformation(UserIdentifier &user_identifier,
                                 CashOperator &cash_operator);


 private:
  void DisplayUserInformation(const std::string &info_title,
                              const std::string &value) const;

  SystemUtility utility_;
};

#endif  // ACCOUNT_INFORMATOR_H
