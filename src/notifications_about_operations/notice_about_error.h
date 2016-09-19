#ifndef NOTICE_ABOUT_ERROR_H
#define NOTICE_ABOUT_ERROR_H

#include <iostream>
#include "refill_messenger.h"
#include "system_utility.h"

using std::cout;
using std::cin;

class NoticeAboutError {
 public:
  NoticeAboutError();

  void ShowUnacceptableWithdrawal(int amount_of_cash, int incorrect_sum);

  void NoticeAboutIncorrectLoginMessage() const;
  void NoticeAboutIncorrectFormatPasswordMessage() const;
  void NoticeAboutIncorrectDataMessage() const;
  void NoticeAboutIncorrectSum() const;

  bool ShowIncorrectDataMessage();

 private:
  SystemUtility utility_;
  RefillMessenger refill_messenger_;
};

#endif  // NOTICE_ABOUT_ERROR_H
