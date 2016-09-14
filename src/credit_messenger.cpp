#include "credit_messenger.h"

void CreditMessanger::RefusToGrantAnotherCredit() const {
  utility_.WriteTextWithDelay(
      "\n #Sorry, but you have already a "
      "loan in our bank.\n"
      " #You can't get a second loan, "
      "while your first loan "
      "not complete.\n");
}

void CreditMessanger::ShowNotifyAboutCredit() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# You can get a loan in our bank if your\n"
      "  balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "  our bank may refuse you in getting a loan\n"
      "  without giving any reason.\n"
      "# Nowadays, the all loans are set on 14% per year\n"
      "# The loan depend from sum on account at the moment.\n");

  cout << "\n\t*********************\n"
          "\t*   Continue?       *\n"
          "\t*                   *\n"
          "\t*   1. Yes          *\n"
          "\t*   2. No           *\n"
          "\t*                   *\n"
          "\t*********************\n"
          "\tEnter: ";
}

void CreditMessanger::ShowCreditConditions(
    const int maximal_sum_of_credit) const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximum amount for you is:");
  utility_.Sleep(500);
  cout << "----------------------------------------------------------\n";
  cout << " \t\t\t $" << maximal_sum_of_credit << "\n";
  cout << "----------------------------------------------------------\n";
  utility_.Sleep(500);
  utility_.WriteTextWithDelay(
      "\n# Do you prefer get all sum or you want to change the sum of "
      "loan?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of loan\n"
      "# 3. Main menu\n"
      "# 4. Exit\n");
  cout << "# Enter: ";
}

void CreditMessanger::ShowInfoAboutCredit(
    const CreditMessanger::string &user_login, const int max_sum) const {
  cout << "\t             Consumer credit\n"
          "\t* Profile: "
       << user_login << "\n\t* Sum $: " << max_sum
       << "\n\t* Persent per year: 14%\n\n ";
}

CreditMessanger::string CreditMessanger::SuggestToConfirmACredit() const {
  string menu_text(
      "\n\t# Do you confirm the loan?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. No, go to the main.\n"
      "\t3. Exit program.\n");

  return menu_text;
}

void CreditMessanger::ShowIndividualCreditInfo(
    const CreditMessanger::string &user_login, const int sum_of_credit) const {
  cout << "\t\tConsumer Credit\n\n";
  utility_.Sleep(500);
  cout << "Profile: " << user_login << "\n";
  utility_.Sleep(500);
  cout << "Sum $: " << sum_of_credit << "\n";
  utility_.Sleep(500);
  cout << "Persent per year: 14%\n\n";
  utility_.Sleep(2500);
}

void CreditMessanger::ShowEnrollACredit() const {
  utility_.WriteTextWithDelay(
      "\n# The loan was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.");
  utility_.IgnoreCinLine();
}

void CreditMessanger::ShowRefuseACredit(const int sum_of_cash) const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("# We checked your balance.\n");
  utility_.Sleep(500);
  cout << "# Available cash = $" << sum_of_cash << "\n";
  utility_.WriteTextWithDelay(
      "# Sorry, for getting a loan your balance must be "
      "$1000 or more.\n");
  utility_.Sleep(500);
}
