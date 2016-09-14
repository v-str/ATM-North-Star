#include "secondary_credit_operations.h"

bool SecondaryCreditOperations::EnrollACredit(UserIdentifier &user_identifier,
                                              const int sum_of_credit,
                                              const int pay_per_month) const {
  user_identifier.AssignACredit(sum_of_credit);
  user_identifier.AssignAMonthlyPayment(pay_per_month);
  credit_messenger_.ShowEnrollACredit();
  return user_input_.SuggestUserToExit();
}

bool SecondaryCreditOperations::RepealACredit(
    UserIdentifier &user_identifier) const {
  user_identifier.AssignACredit(0);
  user_identifier.AssignAMonthlyPayment(0.0);
  credit_messenger_.ShowRepealACreadit();
  return user_input_.SuggestUserToExit();
}

int SecondaryCreditOperations::GetAmountOfCreditMonthsFromUser(
    UserIdentifier &user_identifier) {
  cout << "\nThe number of months to repay the loan: ";
  int months;
  cin >> months;
  user_identifier.InitAmountOfCreditMonth(months);
  utility_.IgnoreCinLine();
  return months;
}
