#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include <string>

#include "cash_operator.h"
#include "notice_about_error.h"
#include "notice_about_successful_action.h"
#include "user_identifier.h"
#include "user_messenger.h"
#include "registration_messenger.h"

class UserRegistrator {
  using string = std::string;

 public:
  void Register(CashOperator &cash_operator, UserIdentifier &user_identifier);

 private:
  CashOperator cash_operator_;
  UserIdentifier user_identifier_;
  UserMessenger user_messenger_;
  NoticeAboutError error_message_;
  NoticeAboutSuccessfulAction successful_action_;
  RegistrationMessenger registation_messenger_;
};

#endif  // USER_REGISTRATOR_H
