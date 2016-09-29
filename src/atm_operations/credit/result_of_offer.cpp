#include "result_of_offer.h"

bool ResultOfOffer::SuggestACredit(CashOperator &cash_operator, int choice,
                                   int sum_of_credit, int pay_per_month) const {
  if (choice == kEnroll) {
    cash_operator.GetAssignACredit(sum_of_credit);
    cash_operator.AssignAMonthlyPayment(pay_per_month);
    credit_messenger_.ShowResultOfUserChoice(kEnroll);
    return user_input_.SuggestUserToExit();

  } else if (choice == kRepeal) {
    cash_operator.GetAssignACredit(0);
    cash_operator.AssignAMonthlyPayment(0.0);
    cash_operator.SetAmountOfCreditMonth(0);
    credit_messenger_.ShowResultOfUserChoice(kRepeal);
    return user_input_.SuggestUserToExit();

  } else if (choice == kExit) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_operation_.ShowIncorrectDataMessage();
  }
}
