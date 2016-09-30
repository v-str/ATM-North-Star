#include "primary_credit_operations.h"

static const int kRatePerYear = 14;
static const int kFullRate = 100;
static const int kOneYear = 12;

bool PrimaryCreditOperations::CollectCreditData(
    CashOperator &cash_operator, const string &user_login,
    const credit maximal_sum_of_credit, const credit credit_mode) {
  credit user_sum_of_credit =
      GetSumOfCredit(maximal_sum_of_credit, credit_mode);

  credit credit_months = GetMonthOfCredit(cash_operator);

  credit_messenger_.ShowCreditTitle(user_login, user_sum_of_credit);

  double pay_per_month =
      GetMonthlyCreditPay(user_sum_of_credit, credit_months);

  string credit_confirmation_text = credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(
      credit_confirmation_text, credit_messenger_.ShowEnter());

  return credit_offer_.SuggestACredit(cash_operator, choice,
                                         user_sum_of_credit, pay_per_month);
}

credit PrimaryCreditOperations::GetSumOfCredit(
    const credit maximal_sum_of_credit, const credit credit_mode) {
  return secondary_credit_operation_.GetCreditMode(maximal_sum_of_credit,
                                                   credit_mode);
}

credit PrimaryCreditOperations::GetMonthOfCredit(CashOperator &cash_operator) {
  credit credit_months = secondary_credit_operation_.GetCreditMonth();
  cash_operator.SetAmountOfCreditMonth(credit_months);
  return credit_months;
}

double PrimaryCreditOperations::GetMonthlyCreditPay(
    credit sum_of_credit, credit amount_of_credit_months) {
  double rate = (sum_of_credit * kRatePerYear) / kFullRate;
  double pay_per_month =
      (sum_of_credit / amount_of_credit_months) + (rate / kOneYear);
  credit_messenger_.ShowCalculationOfCredit(pay_per_month,
                                            amount_of_credit_months);
  return pay_per_month;
}
