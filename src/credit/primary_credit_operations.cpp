#include "primary_credit_operations.h"

bool PrimaryCreditOperations::MaxCreditCalculation(
    UserIdentifier &user_identifier, int maximal_sum_of_credit) {
  int amount_of_credit_months =
      secondary_credit_operation_.GetAmountOfCreditMonthsFromUser(
          user_identifier);

  utility_.ClearScreen();

  string user_login = user_identifier.ReturnLogin();

  credit_messenger_.ShowInfoAboutCredit(user_login, maximal_sum_of_credit);

  double pay_per_month =
      CalculateCredit(maximal_sum_of_credit, amount_of_credit_months);

  string menu_text = credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(menu_text, "\tEnter: ");

  if (choice == 1) {
    return secondary_credit_operation_.EnrollACredit(
        user_identifier, maximal_sum_of_credit, pay_per_month);
  } else if (choice == 2) {
    return secondary_credit_operation_.RepealACredit(user_identifier);
  } else if (choice == 3) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_.ShowIncorrectDataMessage();
  }
}

double PrimaryCreditOperations::CalculateCredit(const int sum,
                                                const int amount_of_months) {
  double rate = (sum * 14) / 100;
  double pay_per_month = (sum / amount_of_months) + (rate / 12);
  double all_payment = 0.0;
  for (int i = 0; i < amount_of_months; ++i) {
    cout << "\t* Payment month: " << i + 1 << "\tPayment sum: ";
    cout << pay_per_month << " $\n";
    utility_.Sleep(75);
    all_payment += pay_per_month;
  }
  cout << "\t\t\tTotal: " << all_payment << " $\n\n";
  return pay_per_month;
}
