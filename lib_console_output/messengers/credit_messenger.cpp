#include "credit_messenger.h"
#include "text_writer.h"

void CreditMessenger::RefuseACreditBasedOnAnotherCredit() const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelayPerSymbol(
      "# Sorry, but you have already credit in our bank.\n"
      "# You can't get a second credit, while your first\n"
      "# credit is not complete.\n");
}

void CreditMessenger::RefuseACreditBasedOnCash(int sum_of_cash) const {
  console_editor_.ClearScreen();

  console_editor_.WriteTextWithInterrupt("# We checked your balance.\n",
                                         kHalfASecond);

  console_editor_.WriteTextWithInterrupt(
      "# Available cash = $" + std::to_string(sum_of_cash) + "\n" +
          "# Sorry, for getting a credit your balance must be "
          "$1000 or more.\n",
      kHalfASecond);
}

void CreditMessenger::NotifyAboutCredit() const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelayPerSymbol(
      "# You can get a credit in our bank if your\n"
      "# balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "# our bank may refuse you in getting a credit\n"
      "# without giving any reason.\n"
      "# Nowadays, all credits are set on 14% per year\n"
      "# The credit depend from sum on account at the moment.\n");

  console_editor_.WriteText(
      "\n#####################\n"
      "#   Continue?       #\n"
      "#                   #\n"
      "#   1. Yes          #\n"
      "#   2. No           #\n"
      "#                   #\n"
      "#####################\n\n"
      "Enter: ");
}

void CreditMessenger::ShowCreditConditions(int maximal_sum_of_credit) const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithInterrupt(
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximal credit sum for you is:\n",
      kHalfASecond);

  console_editor_.WriteSymbolsNTimes("-", 70);
  console_editor_.WriteText("\n");
  console_editor_.WriteText(" \t\t\t | $");
  std::string convertible_string_value =
      console_editor_.ConvertValueToString(maximal_sum_of_credit);
  console_editor_.WriteText(convertible_string_value);
  console_editor_.WriteText(" |\n");
  console_editor_.WriteSymbolsNTimes("-", 70);
  console_editor_.WriteText("\n");

  console_editor_.WriteTextWithInterrupt(
      "\n# Do you prefer get all sum or you want to change\nthe sum of "
      "credit?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of credit\n"
      "# 3. Exit credit menu\n",
      kHalfASecond);
  console_editor_.WriteText("# Enter: ");
}

void CreditMessenger::SuggestToConfirmACredit() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\t# Do you confirm the credit?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. Repeal a credit.\n"
      "\tEnter: ");
}

void CreditMessenger::ShowCreditTitle(const string& user_login,
                                      int sum_of_credit) const {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();

  console_editor_.WriteTextWithInterrupt("\t\tConsumer Credit\n\n",
                                         kHalfASecond);

  console_editor_.WriteTextWithInterrupt("Profile: " + user_login + "\n",
                                         kHalfASecond);

  console_editor_.WriteTextWithInterrupt(
      "Sum $: " + std::to_string(sum_of_credit) + "\n", kHalfASecond);

  console_editor_.WriteTextWithInterrupt("Persent per year: 14%\n\n",
                                         kHalfASecond);
}

void CreditMessenger::EnrollACredit() const {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.WriteTextWithDelayPerSymbol(
      "# The credit was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.\n");
}

void CreditMessenger::RepealACreadit() const {
  console_editor_.WriteTextWithDelayPerSymbol("\n\t# Credit is repealed...\n");
}

void CreditMessenger::ShowCreditTable(double pay_per_month,
                                      double amount_of_months) const {
  double all_payment = 0.0;

  for (int i = kNull + 1; i <= amount_of_months; ++i) {
    console_editor_.WriteText("\t* Payment month: " + std::to_string(i) +
                              "\tPayment sum: ");

    std::string convertible_pay_per_month_value =
        console_editor_.ConvertValueToString(pay_per_month);

    console_editor_.WriteTextWithInterrupt(
        convertible_pay_per_month_value + "$\n", kSleep);
    all_payment += pay_per_month;
  }
  std::string convertible_all_payment_value =
      console_editor_.ConvertValueToString(pay_per_month);
  console_editor_.WriteText("\t\t\tTotal: " + convertible_all_payment_value +
                            " $");
  console_editor_.AddEmptyLineNTimes(2);
}

void CreditMessenger::ShowInfoAboutCreditSum() const {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteSymbolsNTimes("-", 70);
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteTextWithDelayPerSymbol(
      "The entered sum should:\n\n"
      "\t- not exceed the allowed credit.\n"
      "\t- be greater than minimal sum of credit equal $500.\n");
  console_editor_.WriteSymbolsNTimes("-", 70);
}

void CreditMessenger::SuggestEnterCreditSum() const {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteTextWithDelayPerSymbol(
      "Enter the desired sum of credit: $");
}

void CreditMessenger::ShowError(const string& error_message) const {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteSymbolsNTimes(" . ", 20);
  console_editor_.WriteText("\n    ");
  console_editor_.WriteTextWithDelayPerSymbol("Error! " + error_message);
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteSymbolsNTimes(" . ", 20);
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.Sleep(500);
}

void CreditMessenger::ShowDataConfirmation() const {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteSymbolsNTimes(":", 20);
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteTextWithDelayPerSymbol(":: Data confirmed ::");
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteSymbolsNTimes(":", 20);
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.Sleep(750);
}

void CreditMessenger::ShowInfoAboutCreditTerm() const {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.WriteSymbolsNTimes("-", 70);
  console_editor_.WriteTextWithDelayPerSymbol(
      "\nThe entered credit term should:\n\n"
      "\t- not exceed 60 months ( 5 years )\n"
      "\t- be greater than minimal credit term equal 6 months.\n");
  console_editor_.WriteSymbolsNTimes("-", 70);
}

void CreditMessenger::SuggestEnterCreditTerm() const {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteTextWithDelayPerSymbol(
      "Enter the desired term of credit: $");
}

void CreditMessenger::ShowResultOfUserChoice(int decision_of_user) const {
  if (decision_of_user == 1) {
    EnrollACredit();
  } else {
    RepealACreadit();
  }
}

void CreditMessenger::ShowIncorrectCashInformation(int cash) const {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteSymbolsNTimes("-", 65);
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteText(" Balance: $" + std::to_string(cash) + " ");
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteSymbolsNTimes("-", 65);
  console_editor_.AddEmptyLineNTimes(1);
}

void CreditMessenger::ShowUnavailableCreditInfo() const {
  console_editor_.ClearScreen();
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.WriteTextWithDelayPerSymbol("\tCredit is not available!");
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.Sleep(500);
}

void CreditMessenger::UnavailableCreditState() const {
  console_editor_.ClearScreen();
  console_editor_.WriteSymbolsNTimes("#", 65);
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteTextWithDelayPerSymbol(
      " # Sorry, credit section is not available at the moment,\n"
      " # Try later . . .\n");
  console_editor_.WriteSymbolsNTimes("#", 65);
  console_editor_.AddEmptyLineNTimes(1);
}
