#include "primary_credit_operations.h"

static const int kRatePerYear = 14;
static const int kFullRate = 100;
static const int kOneYear = 12;

bool PrimaryCreditOperations::CollectCreditData(CashOperator &cash_operator,
                                                const string &user_login,
                                                credit maximal_sum_of_credit,
                                                credit credit_mode) {
  credit user_sum_of_credit = secondary_credit_operation_.GetCreditMode(
      maximal_sum_of_credit, credit_mode);

  credit amount_of_credit_months = secondary_credit_operation_.GetCreditMonth();

  cash_operator.SetAmountOfCreditMonth(amount_of_credit_months);

  utility_.ClearScreen();

  credit_messenger_.ShowIndividualCreditInfo(user_login, user_sum_of_credit);

  double pay_per_month =
      GetMonthlyCreditPayment(user_sum_of_credit, amount_of_credit_months);

  string credit_confirmation_text = credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(
      credit_confirmation_text, credit_messenger_.ShowEnter());

  return result_of_offer_.SuggestACredit(cash_operator, choice,
                                         user_sum_of_credit, pay_per_month);
}

double PrimaryCreditOperations::GetMonthlyCreditPayment(
    credit sum_of_credit, credit amount_of_credit_months) {
  double rate = (sum_of_credit * kRatePerYear) / kFullRate;
  double pay_per_month =
      (sum_of_credit / amount_of_credit_months) + (rate / kOneYear);
  credit_messenger_.ShowCalculationOfCredit(pay_per_month,
                                            amount_of_credit_months);
  return pay_per_month;
}
