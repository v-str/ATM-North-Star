#include "primary_credit_operations.h"

static const int kRatePerYear = 14;
static const int kFullRate = 100;
static const int kOneYear = 12;
static const int kConsumerCredit = 1;

bool PrimaryCreditOperations::CollectCreditData(CashOperator &cash_operator,
                                                  const string &user_login,
                                                  int maximal_sum_of_credit,
                                                  int credit_variant) {
  int user_sum_of_credit = secondary_credit_operation_.CalculateCreditSum(
      maximal_sum_of_credit, credit_variant);

  int amount_of_credit_months = secondary_credit_operation_.GetMonth();

  cash_operator.SetAmountOfCreditMonth(amount_of_credit_months);

  utility_.ClearScreen();

  credit_messenger_.ShowIndividualCreditInfo(user_login, user_sum_of_credit);

  double pay_per_month =
      CalculateCredit(user_sum_of_credit, amount_of_credit_months);

  string loan_confirmation_menu_text =
      credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(
      loan_confirmation_menu_text, credit_messenger_.ShowEnter());

  return result_of_offer_.SuggestACredit(cash_operator, choice,
                                         user_sum_of_credit, pay_per_month);
}

double PrimaryCreditOperations::CalculateCredit(int sum_of_credit,
                                                int amount_of_months) {
  double rate = (sum_of_credit * kRatePerYear) / kFullRate;
  double pay_per_month = (sum_of_credit / amount_of_months) + (rate / kOneYear);
  credit_messenger_.ShowCalculationOfCredit(pay_per_month, amount_of_months);
  return pay_per_month;
}
