#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include "iostream"
#include "string"

#include "cash_operator.h"
#include "system_utility.h"
#include "user_input.h"

class CreditMessanger {
  using string = std::string;

 public:
  void RefusToGrantAnotherCredit() const;
  void ShowNotifyAboutCredit() const;
  void ShowCreditConditions(int maximal_sum_of_credit) const;
  void ShowInfoAboutCredit(const string &user_login, int max_sum) const;

  string SuggestToConfirmACredit() const;
  void ShowCreditTitle(const string &user_login, int sum_of_credit) const;

  void ShowEnrollACredit() const;
  void ShowRefuseACredit(int sum_of_cash) const;

  void ShowRepealACreadit() const;

  void ShowTableOfCredit(const double pay_per_month,
                         const double amount_of_months) const;

  void ShowAmountOfMonthToPayACredit() const;

  void ShowResultOfUserChoice(int decision_of_user) const;

  void ShowIncorrectCashInformation(const CashOperator &cash_operator) const;

  string ShowEnterText() const;

 private:
  static const int kHalfASecond = 500;
  static const int kSleep = 75;
  static const int kNull = 0;

  SystemUtility utility_;
  UserInput user_input_;
};

#endif  // CREDIT_MESSANGER_H
