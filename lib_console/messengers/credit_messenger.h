#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include <string>

class CreditMessenger {
 public:
  static void RefuseACreditBasedOnAnotherCredit();
  static void RefuseACreditBasedOnCash(int sum_of_cash);
  static void NotifyAboutCredit();
  static void ShowCreditConditions(int maximal_sum_of_credit);
  static void SuggestToConfirmACredit();
  static void EnrollACredit();
  static void RepealACreadit();
  static void ShowInfoAboutCreditSum();
  static void SuggestEnterCreditSum();
  static void ShowInfoAboutCreditTerm();
  static void SuggestEnterCreditTerm();
  static void ShowError(const std::string& error_message);
  static void ShowDataConfirmation();
  static void ShowIncorrectCashInformation(int cash);
  static void UnavailableCreditState();

 private:
  static constexpr int kHalfASecond = 500;
  static constexpr int kSleep = 75;
  static constexpr int kNull = 0;
};

#endif  // CREDIT_MESSANGER_H
