#include "credit_offer.h"

void CreditOffer::SuggestACredit(CashOperator &cash_operator,
                                 const std::string &user_login,
                                 int sum_of_credit,
                                 int amount_of_months) const {
  credit_page_.ShowTitle(user_login, sum_of_credit);
  cash_operator.SetAmountOfCreditMonth(amount_of_months);
  double pay_per_month = secondary_credit_operation_.CalculateMonthlyPayment(
      sum_of_credit, amount_of_months);

  credit_messenger_.SuggestToConfirmACredit();

  int user_choice = user_input_.GetValueFromUser();

  if (user_choice == kEnroll) {
    DoCreditOperation(cash_operator, sum_of_credit, pay_per_month);

  } else if (user_choice == kRepeal) {
    DoCreditOperation(cash_operator);
  } else {
    cash_operator.SetAmountOfCreditMonth(0);
    notice_messenger_.ShowError();
  }
}

int CreditOffer::GetCreditChoice() const {
  credit_messenger_.SuggestToConfirmACredit();

  int credit_choice = user_input_.GetValueFromUser();

  return credit_choice;
}

void CreditOffer::DoCreditOperation(CashOperator &cash_operator,
                                    int sum_of_credit,
                                    double pay_per_month) const {
  cash_operator.GetAssignACredit(sum_of_credit);
  cash_operator.AssignAMonthlyPayment(pay_per_month);
  credit_messenger_.ShowResultOfUserChoice(kEnroll);
}

void CreditOffer::DoCreditOperation(CashOperator &cash_operator) const {
  cash_operator.GetAssignACredit(0);
  cash_operator.AssignAMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
  credit_messenger_.ShowResultOfUserChoice(kRepeal);
}
