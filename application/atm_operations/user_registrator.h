#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include <string>

#include <atm_user.h>
#include <notice_messenger.h>
#include <user_identification_data_provider.h>

class UserRegistrator {
 public:
  void RegisterUser(AtmUser& atm_user);

  bool SetRegistrationStatus() const;

  // New code
  void RegisterUser();

  std::string GetUserLogin() const;

 private:
  void EnterLogin(AtmUser& atm_user);
  void EnterPassword(AtmUser& atm_user);

  void SetRegistrationStatus(bool is_correct_registration);

  bool registration_status_ = false;

  UserIdentificationDataProvider provider_;
  NoticeMessenger notice_messenger_;

  // new code

  // new code

  std::string login_ = "user";
  std::string password_ = "password";
};

#endif  // USER_REGISTRATOR_H
