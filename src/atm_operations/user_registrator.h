#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include "atm_user.h"
#include "identification_messenger.h"
#include "notice_messenger.h"
#include "registration_messenger.h"
#include "user_identification_data_provider.h"

class UserRegistrator {
 public:
  void RegisterUser(AtmUser& atm_user);

  bool IsCorrectRegistration() const;

 private:
  static void AssignInitialValues(AtmUser& atm_user);

  void EnterLogin(AtmUser& atm_user);
  void EnterPassword(AtmUser& atm_user);

  void set_is_correct_registration(bool is_correct_registration);

  bool correct_registration_ = false;

  RegistrationMessenger registation_messenger_;
  UserIdentificationDataProvider provider_;
  IdentificationMessenger identification_messenger_;

  NoticeMessenger notice_messenger_;
};

#endif  // USER_REGISTRATOR_H
