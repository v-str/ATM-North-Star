#include "secondary_credit_operations.h"

bool SecondaryCreditOperations::EnrollACredit() const {

  credit_messenger_.ShowEnrollACredit();
  return user_input_.SuggestUserToExit();
}

bool SecondaryCreditOperations::RepealACredit(
    CashOperator &cash_operator) const {
  cash_operator.GetAssignACredit(0);
  cash_operator.AssignAMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
  credit_messenger_.ShowRepealACreadit();
  return user_input_.SuggestUserToExit();
}

int SecondaryCreditOperations::GetAmountOfCreditMonthsFromUser() {
  return GetMonth();
}

int SecondaryCreditOperations::GetIndividualSumOfCreditFromUser(
    int maximal_sum_of_credit) {
  int user_sum_of_credit = 0;
  do {
    error_.NoticeAboutIncorrectMonths();
    cin >> user_sum_of_credit;
    utility_.IgnoreCinLine();
  } while (user_sum_of_credit > maximal_sum_of_credit);
  return user_sum_of_credit;
}

int SecondaryCreditOperations::GetMonth() {
  cout << "\nThe number of months to repay the loan: ";
  int months = 0;
  cin >> months;
  utility_.IgnoreCinLine();
  return months;
}
