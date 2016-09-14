#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include "iostream"
#include "string"

#include "system_utility.h"
#include "user_input.h"

using std::cout;

class CreditMessanger {
  using string = std::string;

 public:
  void RefusToGrantAnotherCredit() const;
  void ShowNotifyAboutCredit() const;
  void ShowCreditConditions(const int maximal_sum_of_credit) const;
  void ShowInfoAboutCredit(const string &user_login, const int max_sum) const;

  string SuggestToConfirmACredit() const;
  void ShowIndividualCreditInfo(const string &user_login,
                                const int sum_of_credit) const;

  void ShowEnrollACredit() const;
  void ShowRefuseACredit(const int sum_of_cash) const;

  bool ShowExitMessage() const;
  void ShowRepealACreadit() const;

 private:
  SystemUtility utility_;
  UserInput user_input_;
};

#endif  // CREDIT_MESSANGER_H
