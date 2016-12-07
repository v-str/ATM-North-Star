#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include "console_editor.h"

#include <string>

class CreditMessanger {
  using string = std::string;

 public:
  void RefuseToGrantAnotherCredit() const;
  void ShowNotifyAboutCredit() const;
  void ShowCreditConditions(int maximal_sum_of_credit) const;
  void ShowInfoAboutCredit(const string &user_login, int max_sum) const;

  void SuggestToConfirmACredit() const;
  void ShowCreditTitle(const string &user_login, int sum_of_credit) const;

  void ShowEnrollACredit() const;
  void ShowRefuseACredit(int sum_of_cash) const;

  void ShowRepealACreadit() const;

  void ShowTableOfCredit(const double pay_per_month,
                         const double amount_of_months) const;

  void ShowAmountOfMonthToPayACredit() const;

  void ShowResultOfUserChoice(int decision_of_user) const;

  void ShowIncorrectCashInformation(int cash) const;

  string ShowEnterText() const;

 private:
  static const int kHalfASecond = 500;
  static const int kSleep = 75;
  static const int kNull = 0;

  ConsoleEditor console_editor_;
};

#endif  // CREDIT_MESSANGER_H
