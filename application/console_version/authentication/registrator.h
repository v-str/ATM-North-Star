#ifndef REGISTRATOR_H
#define REGISTRATOR_H

#include <string>

#include <atm_user.h>
#include <notice_messenger.h>
#include <user_identification_data_provider.h>

#include <authenticator.h>
#include <menu_input_handler.h>
#include <user_input_handler.h>

class Registrator {
 public:
  void RunRegistrationMenu(AtmUser& atm_user);

  bool RegistrationStatus() const;

  std::string GetUserLogin() const;

  // New code
  void RunRegistrationMenu();

 private:
  void EnterLogin(AtmUser& atm_user);
  void EnterPassword(AtmUser& atm_user);

  void SetRegistrationStatus(bool is_correct_registration);

  //
  // new code
  //

  enum RegistrationMenuPoints { kSymbolQuit, kStartRegistration, kDigitQuit };

  void ConfirmRegistration();

  UserIdentificationDataProvider provider_;
  NoticeMessenger notice_messenger_;

  Authenticator authenticator_;
  UserInputHandler user_input_;
  MenuInputHandler menu_input_;

  std::string login_ = "user";
  std::string password_ = "password";

  bool registration_status_ = false;
};

#endif  // REGISTRATOR_H
