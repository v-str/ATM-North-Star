#include "secondary_credit_operations.h"

bool SecondaryCreditOperations::EnrollACredit(CashOperator &cash_operator,
                                              int sum_of_credit,
                                              int pay_per_month) const {
  cash_operator.GetAssignACredit(sum_of_credit);
  cash_operator.AssignAMonthlyPayment(pay_per_month);
  credit_messenger_.ShowEnrollACredit();
  return user_input_.SuggestUserToExit();
}

bool SecondaryCreditOperations::RepealACredit(
        CashOperator &cash_operator
    ) const {
  cash_operator.GetAssignACredit(0);
  cash_operator.AssignAMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
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
  int user_sum_of_credit = 0;
  do {
    utility_.WriteTextWithDelay(
        "The entered amount should not "
        "exceed the allowed credit.\n"
        "Enter the appropriate amount of credit: ");
    cout << "Enter: ";
    cin >> user_sum_of_credit;

    utility_.IgnoreCinLine();
  } while (user_sum_of_credit > maximal_sum_of_credit);

  return user_sum_of_credit;
}
