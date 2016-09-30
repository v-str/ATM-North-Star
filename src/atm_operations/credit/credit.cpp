#include "credit.h"

bool Credit::GiveCreditByMode(CashOperator &cash_operator,
                              const string &user_login,
                              const int maximal_sum_of_credit,
                              const int credit_mode) {
  int amount_of_credit =
      AmountOfCreditByMode(maximal_sum_of_credit, credit_mode);

  int amount_of_months = AmountOfCreditMonth(cash_operator);

  return credit_offer_.SuggestACredit(cash_operator, user_login,
                                      amount_of_credit, amount_of_months);
}

int Credit::AmountOfCreditByMode(const int maximal_sum_of_credit,
                                 const int credit_mode) {
  return secondary_credit_operation_.GetCreditMode(maximal_sum_of_credit,
                                                   credit_mode);
}

int Credit::AmountOfCreditMonth(CashOperator &cash_operator) {
  int amount_of_credit_months = secondary_credit_operation_.GetCreditMonth();
  cash_operator.SetAmountOfCreditMonth(amount_of_credit_months);
  return amount_of_credit_months;
}
