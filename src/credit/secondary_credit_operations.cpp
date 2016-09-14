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
