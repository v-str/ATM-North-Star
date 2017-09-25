#ifndef CREDIT_CALCULATOR_MESSENGER_H
#define CREDIT_CALCULATOR_MESSENGER_H

#include <string>

class CreditCalculatorMessenger {
 public:
  static void DisplayCalculatorDescription();
  static void DisplayCreditSumRequest();
  static void DisplayInterestRateRequest();
  static void DisplayAmountOfMonthRequest();

  static void DisplayErrorLogo();
  static void DisplayError(const std::string& error_text);

  static void PressEnterToContinue();
  static void ClearScreen();

 private:
  static void DisplayCorrectInputOrder();
  static void DisplayNotification();
  static void DisplayLogo();
};

#endif  // CREDIT_CALCULATOR_MESSENGER_H
