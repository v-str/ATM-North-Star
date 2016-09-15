#ifndef NOTICE_ABOUT_SUCCESS_FULACTION_H
#define NOTICE_ABOUT_SUCCESS_FULACTION_H

#include <iostream>

#include "account_info.h"
#include "system_utility.h"
#include "user_identifier.h"

using std::cout;

class NoticeAboutSuccessfulAction {
 public:
  void NoticeAboutSuccessfulRegistration(UserIdentifier &user_identifier_) const;

 private:
  SystemUtility utility_;
};

#endif  // NOTICE_ABOUT_SUCCESSFUL_ACTION_H
