#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <iostream>

#include "cash_operator.h"
#include "notice_messenger.h"
#include "system_utility.h"

using std::cout;
using std::cin;

class Notifier {
 public:
  Notifier();

  void NoticeAboutSuccessfulRegistration(CashOperator &cash_operator) const;

  void NoticeUnacceptableWithdrawal(int amount_of_cash,
                                    int incorrect_sum) const;

  void NoticeAboutIncorrectLogin() const;
  void NoticeAboutIncorrectFormatPasswordMessage() const;
  void NoticeAboutIncorrectDataMessage() const;
  void NoticeAboutIncorrectSum() const;

  void ShowIncorrectDataMessage() const;
  void NoticeAboutIncorrectMonths() const;

 private:
  SystemUtility utility_;
  NoticeMessenger notice_messenger_;
};

#endif  // NOTIFIER_H
