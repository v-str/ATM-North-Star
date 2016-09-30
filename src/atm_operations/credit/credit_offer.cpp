#include "credit_offer.h"

bool CreditOffer::SuggestACredit(CashOperator &cash_operator,
                                 const std::__cxx11::string &user_login,
                                 int sum_of_credit, int months) const {
  credit_page_.ShowTitle(user_login, sum_of_credit);

  double pay_per_month = secondary_credit_operation_.CalculateMonthlyPayment(
      sum_of_credit, months);

  int user_choice = GetCreditChoice();

  if (user_choice == kEnroll) {
    return DoACreditOperation(cash_operator, sum_of_credit, pay_per_month);

  } else if (user_choice == kRepeal) {
    return DoACreditOperation(cash_operator);

  } else if (user_choice == kExit) {
    return DoACreditOperation(credit_messenger_);
  } else {
    return DoACreditOperation(cash_operator, error_operation_);
  }
}

int CreditOffer::GetCreditChoice() const {
  string credit_confirmation_text = credit_messenger_.SuggestToConfirmACredit();

  int credit_choice = user_choice_.GetUserChoiceWithMenuText(
      credit_confirmation_text, credit_messenger_.ShowEnter());

  return credit_choice;
}

bool CreditOffer::DoACreditOperation(CashOperator &cash_operator,
                                     int sum_of_credit,
                                     int pay_per_month) const {
  cash_operator.GetAssignACredit(sum_of_credit);
  cash_operator.AssignAMonthlyPayment(pay_per_month);
  credit_messenger_.ShowResultOfUserChoice(kEnroll);
  return user_input_.SuggestUserToExit();
}

bool CreditOffer::DoACreditOperation(CashOperator &cash_operator) const {
  cash_operator.GetAssignACredit(0);
  cash_operator.AssignAMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
  credit_messenger_.ShowResultOfUserChoice(kRepeal);
  return user_input_.SuggestUserToExit();
}

bool CreditOffer::DoACreditOperation(CreditMessanger credit_messenger) const {
  return credit_messenger.ShowExitMessage();
}

bool CreditOffer::DoACreditOperation(CashOperator &cash_operator,
                                     NoticeAboutError error_operation) const {
  cash_operator.SetAmountOfCreditMonth(0);
  return error_operation.ShowIncorrectDataMessage();
}
