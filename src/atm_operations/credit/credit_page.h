#ifndef CREDIT_PAGE_H
#define CREDIT_PAGE_H

#include "credit_messenger.h"

class CreditPage {
 public:
  void ShowTitle(const string &user_login, const int sum_of_credit) const;

 private:
  CreditMessanger credit_messenger_;
};

#endif  // CREDIT_PAGE_H

// Далее Класс CreditOffer тоже следует отрефакторить и переименовать.
// далее....
