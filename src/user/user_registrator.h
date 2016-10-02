#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include <string>

#include "cash_operator.h"
#include "notifier.h"
#include "registration_messenger.h"
#include "user_identifier.h"

class UserRegistrator {
  using string = std::string;

 public:
  void Register(CashOperator &cash_operator, UserIdentifier &user_identifier);

 private:
  Notifier notifier_;
  RegistrationMessenger registation_messenger_;
};

#endif  // USER_REGISTRATOR_H
