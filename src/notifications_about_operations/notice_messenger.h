#ifndef NOTICE_MESSENGER_H
#define NOTICE_MESSENGER_H

#include <iostream>
#include "refill_messenger.h"
#include "system_utility.h"

using std::cout;

class NoticeMessenger {
 public:
  void ShowAcceptableMessageInFrame() const;
  void ShowIncorrectLoginFrame() const;

  void ShowIncorrectFormatPassword() const;
  void ShowIncorrectData() const;
  void ShowIncorrectSum() const;
  void ShowUnacceptableWithdrawal(int incorrect_sum, int amount_of_cash) const;
  void ShowError() const;
  void ShowIncorrectfMonths() const;

 private:
  SystemUtility utility_;
  RefillMessenger refill_messenger_;
};

#endif  // NOTICE_MESSENGER_H
