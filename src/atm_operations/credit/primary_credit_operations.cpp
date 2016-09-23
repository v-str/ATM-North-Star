#include "primary_credit_operations.h"

static const int rate_per_year = 14;
static const int full_rate = 100;
static const int one_year = 12;

bool PrimaryCreditOperations::MaxCreditCalculation(CashOperator &cash_operator,
                                                   const string &user_login,
                                                   int maximal_sum_of_credit) {
  int amount_of_credit_months =
      secondary_credit_operation_.GetAmountOfCreditMonthsFromUser(
          cash_operator);

  utility_.ClearScreen();

  credit_messenger_.ShowInfoAboutCredit(user_login, maximal_sum_of_credit);

  double pay_per_month =
      CalculateCredit(maximal_sum_of_credit, amount_of_credit_months);

  string menu_text = credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(menu_text, "\tEnter: ");

  return SuggestTheCredit(choice, maximal_sum_of_credit, pay_per_month,
                          cash_operator);
}

bool PrimaryCreditOperations::IndividualCreditCalculation(
    CashOperator &cash_operator, const string &user_login,
    int maximal_sum_of_credit) {
  utility_.ClearScreen();

  int user_sum_of_credit =
      secondary_credit_operation_.GetIndividualSumOfCreditFromUser(
          maximal_sum_of_credit);

  int amount_of_credit_months =
      secondary_credit_operation_.GetAmountOfCreditMonthsFromUser(
          cash_operator);

  utility_.ClearScreen();

  credit_messenger_.ShowIndividualCreditInfo(user_login, user_sum_of_credit);

  double pay_per_month =
      CalculateCredit(user_sum_of_credit, amount_of_credit_months);

  string loan_confirmation_menu_text =
      credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(
      loan_confirmation_menu_text, "Enter: ");

  return SuggestTheCredit(choice, user_sum_of_credit, pay_per_month,
                          cash_operator);
}

double PrimaryCreditOperations::CalculateCredit(int sum, int amount_of_months) {
  double rate = (sum * rate_per_year) / full_rate;
  double pay_per_month = (sum / amount_of_months) + (rate / one_year);
  credit_messenger_.ShowCalculationOfCredit(pay_per_month, amount_of_months);
  return pay_per_month;
}

bool PrimaryCreditOperations::SuggestTheCredit(
    const int choice, const int sum_of_credit, const int pay_per_month,
    CashOperator &cash_operator) const {
  if (choice == kenroll) {
    return secondary_credit_operation_.EnrollACredit(
        cash_operator, sum_of_credit, pay_per_month);
  } else if (choice == krepeal) {
    return secondary_credit_operation_.RepealACredit(cash_operator);
  } else if (choice == kexit) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_operation_.ShowIncorrectDataMessage();
  }
}
