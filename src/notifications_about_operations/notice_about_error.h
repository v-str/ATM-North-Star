#ifndef NOTICE_ABOUT_ERROR_H
#define NOTICE_ABOUT_ERROR_H

#include <iostream>
#include "notice_messenger.h"

using std::cout;
using std::cin;

class NoticeAboutError {
 public:
  NoticeAboutError();

  void NoticeUnacceptableWithdrawal(int amount_of_cash,
                                    int incorrect_sum) const;

  void NoticeAboutIncorrectLogin() const;
  void NoticeAboutIncorrectFormatPasswordMessage() const;
  void NoticeAboutIncorrectDataMessage() const;
  void NoticeAboutIncorrectSum() const;

  bool ShowIncorrectDataMessage();

 private:
  NoticeMessenger notice_messenger_;
};

#endif  // NOTICE_ABOUT_ERROR_H
