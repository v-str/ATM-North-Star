#include "credit_messenger.h"
#include "text_writer.h"

#include "iostream"

void CreditMessanger::RefusToGrantAnotherCredit() const {
  console_editor_.WriteTextWithDelay(
      "\n #Sorry, but you have already a "
      "loan in our bank.\n"
      " #You can't get a second loan, "
      "while your first loan "
      "not complete.\n");
}

void CreditMessanger::ShowNotifyAboutCredit() const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelay(
      "# You can get a loan in our bank if your\n"
      "  balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "  our bank may refuse you in getting a loan\n"
      "  without giving any reason.\n"
      "# Nowadays, the all loans are set on 14% per year\n"
      "# The loan depend from sum on account at the moment.\n");

  TextWriter::Write("\n\t*********************\n"
               "\t*   Continue?       *\n"
               "\t*                   *\n"
               "\t*   1. Yes          *\n"
               "\t*   2. No           *\n"
               "\t*                   *\n"
               "\t*********************\n"
               "\tEnter: ");
}

void CreditMessanger::ShowCreditConditions(int maximal_sum_of_credit) const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelay(
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximum amount for you is:\n");
  console_editor_.Sleep(kHalfASecond);
  std::cout << "----------------------------------------------------------\n";
  std::cout << " \t\t\t $" << maximal_sum_of_credit << "\n";
  std::cout << "----------------------------------------------------------\n";
  console_editor_.Sleep(kHalfASecond);
  console_editor_.WriteTextWithDelay(
      "\n# Do you prefer get all sum or you want to change the sum of "
      "loan?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of loan\n"
      "# 3. Exit credit menu\n");
  std::cout << "# Enter: ";
}

void CreditMessanger::ShowInfoAboutCredit(
    const CreditMessanger::string &user_login, int max_sum) const {
  std::cout << "\t             Consumer credit\n"
               "\t* Profile: "
            << user_login << "\n\t* Sum $: " << max_sum
            << "\n\t* Persent per year: 14%\n\n ";
}

void CreditMessanger::SuggestToConfirmACredit() const {
  string menu_text(
      "\n\t# Do you confirm the loan?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. Repeal a credit.\n"
      "\tEnter: ");
  console_editor_.WriteTextWithDelay(menu_text);
}

void CreditMessanger::ShowCreditTitle(const CreditMessanger::string &user_login,
                                      int sum_of_credit) const {
  console_editor_.ClearScreen();
  std::cout << "\t\tConsumer Credit\n\n";
  console_editor_.Sleep(kHalfASecond);
  std::cout << "Profile: " << user_login << "\n";
  console_editor_.Sleep(kHalfASecond);
  std::cout << "Sum $: " << sum_of_credit << "\n";
  console_editor_.Sleep(kHalfASecond);
  std::cout << "Persent per year: 14%\n\n";
  console_editor_.Sleep(kHalfASecond);
}

void CreditMessanger::ShowEnrollACredit() const {
  console_editor_.WriteTextWithDelay(
      "\n# The loan was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.");
}

void CreditMessanger::ShowRepealACreadit() const {
  console_editor_.WriteTextWithDelay("\n\t# Credit is repealed...\n");
}

void CreditMessanger::ShowRefuseACredit(int sum_of_cash) const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelay("# We checked your balance.\n");
  console_editor_.Sleep(kHalfASecond);
  std::cout << "# Available cash = $" << sum_of_cash << "\n";
  console_editor_.WriteTextWithDelay(
      "# Sorry, for getting a loan your balance must be "
      "$1000 or more.\n");
  console_editor_.Sleep(kHalfASecond);
}

void CreditMessanger::ShowTableOfCredit(const double pay_per_month,
                                        const double amount_of_months) const {
  double all_payment = 0.0;
  for (int i = kNull; i < amount_of_months; ++i) {
    std::cout << "\t* Payment month: " << i + 1 << "\tPayment sum: ";
    std::cout << pay_per_month << " $\n";
    console_editor_.Sleep(kSleep);
    all_payment += pay_per_month;
  }
  std::cout << "\t\t\tTotal: " << all_payment << " $\n\n";
}

void CreditMessanger::ShowAmountOfMonthToPayACredit() const {
  std::cout << "Number of credit month can't be more than 60\n";
  std::cout << "Please enter the number of months"
               "\nto repay the credit: ";
}

void CreditMessanger::ShowResultOfUserChoice(int decision_of_user) const {
  if (decision_of_user == 1) {
    ShowEnrollACredit();
  } else {
    ShowRepealACreadit();
  }
}

void CreditMessanger::ShowIncorrectCashInformation(int cash) const {
  console_editor_.WriteSymbolsNTimes('-', 30);
  std::cout << "Balance: " << cash;
  console_editor_.WriteSymbolsNTimes('-', 30);
}

CreditMessanger::string CreditMessanger::ShowEnterText() const {
  return "\t# Enter: ";
}
