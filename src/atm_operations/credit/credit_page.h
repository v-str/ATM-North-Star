#ifndef CREDIT_PAGE_H
#define CREDIT_PAGE_H

#include "credit_messenger.h"
#include "string"

typedef int credit;

class CreditPage {
  using string = std::string;

 public:
  void ShowTitle(const string &user_login, const credit sum_of_credit) const;



 private:
  CreditMessanger credit_messenger_;
};

#endif  // CREDIT_PAGE_H

// 1
// credit_messenger_.ShowCreditTitle(user_login, user_sum_of_credit);

// 2
// credit_messenger_.ShowTableOfCredit(pay_per_month,amount_of_credit_months);
