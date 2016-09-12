#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include "iostream"

#include "system_utility.h"

using std::cout;

class CreditMessanger {
 public:
  CreditMessanger();

  void RefusToGrantAnotherCredit() const;
  void ShowNotifyAboutCredit() const;
  void ShowCreditConditions(const int maximal_sum_of_credit) const;

 private:
  SystemUtility utility_;
};

#endif  // CREDIT_MESSANGER_H
