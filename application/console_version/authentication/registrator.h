#ifndef REGISTRATOR_H
#define REGISTRATOR_H

#include <string>

#include <atm_user.h>
#include <notice_messenger.h>
#include <user_identification_data_provider.h>

class Registrator {
 public:
  void RunRegistration(AtmUser& atm_user);

  bool SetRegistrationStatus() const;

  std::string GetUserLogin() const;

  // New code
  void RunRegistration();

 private:
  void EnterLogin(AtmUser& atm_user);
  void EnterPassword(AtmUser& atm_user);

  void SetRegistrationStatus(bool is_correct_registration);

  bool registration_status_ = false;

  UserIdentificationDataProvider provider_;
  NoticeMessenger notice_messenger_;

  std::string login_ = "user";
  std::string password_ = "password";
};

#endif  // REGISTRATOR_H
