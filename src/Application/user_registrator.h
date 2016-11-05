#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include "cash_operator.h"
#include "identification_messenger.h"
#include "notifier.h"
#include "registration_messenger.h"
#include "user_identification_data_provider.h"
#include "user_identifier.h"

class UserRegistrator {
 public:
  void RegisterUser(CashOperator &cash_operator,
                    UserIdentifier &user_identifier);

  bool IsCorrectRegistration();

 private:
  void EnterLogin(UserIdentifier &user_identifier);
  void EnterPassword(UserIdentifier &user_identifier);
  void set_is_correct_registration(bool is_correct_registration);

  void AssignInitialValues(CashOperator &cash_operator);

  Notifier notifier_;
  RegistrationMessenger registation_messenger_;
  UserIdentificationDataProvider provider_;
  IdentificationMessenger identification_messenger_;

  bool correct_registration_ = false;
};

#endif  // USER_REGISTRATOR_H
