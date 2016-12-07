#include "credit_messenger.h"
#include "text_writer.h"

void CreditMessanger::RefusToGrantAnotherCredit() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n #Sorry, but you have already a "
      "loan in our bank.\n"
      " #You can't get a second loan, "
      "while your first loan "
      "not complete.\n");
}

void CreditMessanger::ShowNotifyAboutCredit() const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelayPerSymbol(
      "# You can get a loan in our bank if your\n"
      "  balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "  our bank may refuse you in getting a loan\n"
      "  without giving any reason.\n"
      "# Nowadays, the all loans are set on 14% per year\n"
      "# The loan depend from sum on account at the moment.\n");

  console_editor_.WriteText(
      "\n\t*********************\n"
      "\t*   Continue?       *\n"
      "\t*                   *\n"
      "\t*   1. Yes          *\n"
      "\t*   2. No           *\n"
      "\t*                   *\n"
      "\t*********************\n"
      "\tEnter: ");
}

void CreditMessanger::ShowCreditConditions(int maximal_sum_of_credit) const {
  std::string convertible_string_value =
      console_editor_.ConvertValueToString(maximal_sum_of_credit);

  console_editor_.ClearScreen();

  console_editor_.WriteTextWithInterrupt(
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximum amount for you is:\n",
      kHalfASecond);
  console_editor_.WriteText(
      "----------------------------------------------------------\n");
  console_editor_.WriteText(" \t\t\t $");
  console_editor_.WriteText(convertible_string_value);
  console_editor_.WriteText("\n");

  console_editor_.WriteText(
      "----------------------------------------------------------\n");

  console_editor_.WriteTextWithInterrupt(
      "\n# Do you prefer get all sum or you want to change the sum of "
      "loan?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of loan\n"
      "# 3. Exit credit menu\n",
      kHalfASecond);
  console_editor_.WriteText("# Enter: ");
}

void CreditMessanger::ShowInfoAboutCredit(
    const CreditMessanger::string &user_login, int max_sum) const {
  std::string convertible_string_value =
      console_editor_.ConvertValueToString(max_sum);

  console_editor_.WriteText(
      "\t             Consumer credit\n"
      "\t* Profile: " +
      user_login + "\n\t* Sum $: " + std::to_string(max_sum) +
      "\n\t* Persent per year: 14%\n\n ");
}

void CreditMessanger::SuggestToConfirmACredit() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\t# Do you confirm the loan?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. Repeal a credit.\n"
      "\tEnter: ");
}

void CreditMessanger::ShowCreditTitle(const CreditMessanger::string &user_login,
                                      int sum_of_credit) const {
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

void CreditMessanger::ShowEnrollACredit() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n# The loan was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.");
}

void CreditMessanger::ShowRepealACreadit() const {
  console_editor_.WriteTextWithDelayPerSymbol("\n\t# Credit is repealed...\n");
}

void CreditMessanger::ShowRefuseACredit(int sum_of_cash) const {
  console_editor_.ClearScreen();

  console_editor_.WriteTextWithInterrupt("# We checked your balance.\n",
                                         kHalfASecond);

  console_editor_.WriteTextWithInterrupt(
      "# Available cash = $" + std::to_string(sum_of_cash) + "\n" +
          "# Sorry, for getting a loan your balance must be "
          "$1000 or more.\n",
      kHalfASecond);
}

void CreditMessanger::ShowTableOfCredit(const double pay_per_month,
                                        const double amount_of_months) const {
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
                            " $\n\n");
}

void CreditMessanger::ShowAmountOfMonthToPayACredit() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\nNumber of credit month can't be more than 60.\n");
  console_editor_.WriteTextWithDelayPerSymbol(
      "Please enter the number of months\nto repay the credit: ");
}

void CreditMessanger::ShowResultOfUserChoice(int decision_of_user) const {
  if (decision_of_user == 1) {
    ShowEnrollACredit();
  } else {
    ShowRepealACreadit();
  }
}

void CreditMessanger::ShowIncorrectCashInformation(int cash) const {
  console_editor_.WriteText("\n");
  console_editor_.WriteSymbolsNTimes("-", 25);
  console_editor_.WriteText(" Balance: $" + std::to_string(cash) + " ");

  console_editor_.WriteSymbolsNTimes("-", 25);
  console_editor_.WriteText("\n");
}

CreditMessanger::string CreditMessanger::ShowEnterText() const {
  return "\t# Enter: ";
}
