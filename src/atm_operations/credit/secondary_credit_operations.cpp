#include "secondary_credit_operations.h"

const int kint_null = 0;
const int kdouble_null = 0.0;

bool SecondaryCreditOperations::EnrollACredit(CashOperator &cash_operator,
                                              int sum_of_credit,
                                              int pay_per_month) const {
  cash_operator.GetAssignACredit(sum_of_credit);
  cash_operator.AssignAMonthlyPayment(pay_per_month);
  credit_messenger_.ShowEnrollACredit();
  return user_input_.SuggestUserToExit();
}

bool SecondaryCreditOperations::RepealACredit(
    CashOperator &cash_operator) const {
  cash_operator.GetAssignACredit(kint_null);
  cash_operator.AssignAMonthlyPayment(kdouble_null);
  cash_operator.SetAmountOfCreditMonth(kint_null);
  credit_messenger_.ShowRepealACreadit();
  return user_input_.SuggestUserToExit();
}

int SecondaryCreditOperations::GetAmountOfCreditMonthsFromUser(
    CashOperator &cash_operator) {
  cout << "\nThe number of months to repay the loan: ";
  int months;
  cin >> months;
  cash_operator.SetAmountOfCreditMonth(months);
  utility_.IgnoreCinLine();
  return months;
}

int SecondaryCreditOperations::GetIndividualSumOfCreditFromUser(
    int maximal_sum_of_credit) {
  int user_sum_of_credit = kint_null;
  do {
    error_.NoticeAboutIncorrectMonths();
    cin >> user_sum_of_credit;
    utility_.IgnoreCinLine();
  } while (user_sum_of_credit > maximal_sum_of_credit);
  return user_sum_of_credit;
}
