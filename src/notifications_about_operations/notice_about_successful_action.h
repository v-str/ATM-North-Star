#ifndef NOTICE_ABOUT_SUCCESS_FULACTION_H
#define NOTICE_ABOUT_SUCCESS_FULACTION_H

#include <iostream>

#include "system_utility.h"
#include "cash_operator.h"
#include "notice_messenger.h"

using std::cout;

class NoticeAboutSuccessfulAction {
 public:
  void NoticeAboutSuccessfulRegistration(
      CashOperator &cash_operator) const;

 private:
  SystemUtility utility_;
  NoticeMessenger notice_messenger_;
};

#endif  // NOTICE_ABOUT_SUCCESSFUL_ACTION_H
