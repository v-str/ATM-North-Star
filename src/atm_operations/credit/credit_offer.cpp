#include "credit_offer.h"

bool CreditOffer::SuggestACredit(CashOperator &cash_operator, credit choice,
                                 credit sum_of_credit, credit pay_per_month) const {
  if (choice == kEnroll) {
    return DoACreditOperation(cash_operator, sum_of_credit, pay_per_month);

  } else if (choice == kRepeal) {
    return DoACreditOperation(cash_operator);

  } else if (choice == kExit) {
    return DoACreditOperation(credit_messenger_);
  } else {
    return DoACreditOperation(cash_operator, error_operation_);
  }
}

credit CreditOffer::GetCreditChoice() {
  string credit_confirmation_text = credit_messenger_.SuggestToConfirmACredit();

  credit credit_choice = user_choice_.GetUserChoiceWithMenuText(
      credit_confirmation_text, credit_messenger_.ShowEnter());

  return credit_choice;
}

bool CreditOffer::DoACreditOperation(CashOperator &cash_operator,
                                     credit sum_of_credit,
                                     credit pay_per_month) const {
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
