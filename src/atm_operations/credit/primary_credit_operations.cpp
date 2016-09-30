#include "primary_credit_operations.h"

static const int kRatePerYear = 14;
static const int kFullRate = 100;
static const int kOneYear = 12;

bool PrimaryCreditOperations::GetCreditData(CashOperator &cash_operator,
                                            const string &user_login,
                                            const credit maximal_sum_of_credit,
                                            const credit credit_mode) {
  credit sum_of_credit = GetSumOfCredit(maximal_sum_of_credit, credit_mode);

  credit months = GetMonthOfCredit(cash_operator);

  credit_page_.ShowTitle(user_login, sum_of_credit);

  double pay_per_month = CalculateMonthlePayment(sum_of_credit, months);

  return credit_offer_.SuggestACredit(cash_operator, sum_of_credit,
                                      pay_per_month);
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

double PrimaryCreditOperations::CalculateMonthlePayment(
    credit sum_of_credit, credit amount_of_credit_months) {
  double rate = (sum_of_credit * kRatePerYear) / kFullRate;
  double pay_per_month =
      (sum_of_credit / amount_of_credit_months) + (rate / kOneYear);
  credit_messenger_.ShowTableOfCredit(pay_per_month, amount_of_credit_months);
  return pay_per_month;
}
