#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include <string>

#include "console_editor.h"

class CreditMessenger {
  using string = std::string;

 public:
  void RefuseACreditBasedOnAnotherCredit() const;
  void RefuseACreditBasedOnCash(int sum_of_cash) const;
  void NotifyAboutCredit() const;
  void ShowCreditConditions(int maximal_sum_of_credit) const;
  void SuggestToConfirmACredit() const;
  void ShowCreditTitle(const string& user_login, int sum_of_credit) const;
  void EnrollACredit() const;
  void RepealACreadit() const;
  void ShowCreditTable(double pay_per_month, double amount_of_months) const;

  void ShowInfoAboutCreditSum() const;
  void SuggestEnterCreditSum() const;
  void ShowError(const string& error_message) const;

  void ShowInfoAboutCreditTerm() const;
  void SuggestEnterCreditTerm() const;
  void ShowResultOfUserChoice(int decision_of_user) const;
  void ShowIncorrectCashInformation(int cash) const;

  /// temporary remark
  void ShowUnavailableCreditInfo() const;
  void UnavailableCreditState() const;

 private:
  static const int kHalfASecond = 500;
  static const int kSleep = 75;
  static const int kNull = 0;

  ConsoleEditor console_editor_;
};

#endif  // CREDIT_MESSANGER_H
