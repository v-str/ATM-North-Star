#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include <string>

class CreditMessenger {
 public:
  void RefuseACreditBasedOnAnotherCredit() const;
  void RefuseACreditBasedOnCash(int sum_of_cash) const;
  void NotifyAboutCredit() const;
  void ShowCreditConditions(int maximal_sum_of_credit) const;
  void SuggestToConfirmACredit() const;
  void EnrollACredit() const;
  void RepealACreadit() const;

  void ShowInfoAboutCreditSum() const;
  void SuggestEnterCreditSum() const;

  void ShowInfoAboutCreditTerm() const;
  void SuggestEnterCreditTerm() const;

  void ShowError(const std::string& error_message) const;
  void ShowDataConfirmation() const;

  void ShowIncorrectCashInformation(int cash) const;

  void UnavailableCreditState() const;

 private:
  static constexpr int kHalfASecond = 500;
  static constexpr int kSleep = 75;
  static constexpr int kNull = 0;
};

#endif  // CREDIT_MESSANGER_H
