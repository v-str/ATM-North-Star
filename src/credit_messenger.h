#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include "iostream"
#include "string"

#include "system_utility.h"

using std::cout;

class CreditMessanger {
  using string = std::string;

 public:
  CreditMessanger();

  void RefusToGrantAnotherCredit() const;
  void ShowNotifyAboutCredit() const;
  void ShowCreditConditions(const int maximal_sum_of_credit) const;
  void ShowInfoAboutCredit(const string &user_login, const int max_sum) const;

  string SuggestToConfirmACredit() const;

 private:
  SystemUtility utility_;
};

#endif  // CREDIT_MESSANGER_H
