#include "credit_offer.h"

void CreditOffer::SuggestACredit(AtmUser *atm_user,
                                 const std::string &user_login,
                                 int sum_of_credit,
                                 int amount_of_months) const {
  credit_messenger_.ShowCreditTitle(user_login, sum_of_credit);

  atm_user->set_amount_of_credit_month(amount_of_months);

  double pay_per_month = secondary_credit_operation_.CalculateMonthlyPayment(
      sum_of_credit, amount_of_months);

  credit_messenger_.SuggestToConfirmACredit();

  int user_choice = user_input_.GetValueFromUser();

  if (user_choice == kEnroll) {
    EnrollCredit(atm_user, sum_of_credit, pay_per_month);

  } else if (user_choice == kRepeal) {
    RepealCredit(atm_user);
  } else {
    atm_user->set_amount_of_credit_month(0);
    notice_messenger_.ShowError();
  }
}

void CreditOffer::EnrollCredit(AtmUser *atm_user, int sum_of_credit,
                               double pay_per_month) const {
  atm_user->get_assigned_credit(sum_of_credit);
  atm_user->AssignAMonthlyPayment(pay_per_month);
  credit_messenger_.ShowResultOfUserChoice(kEnroll);
}

void CreditOffer::RepealCredit(AtmUser *atm_user) const {
  atm_user->get_assigned_credit(0);
  atm_user->AssignAMonthlyPayment(0.0);
  atm_user->set_amount_of_credit_month(0);
  credit_messenger_.ShowResultOfUserChoice(kRepeal);
}
