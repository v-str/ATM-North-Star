#include "user_registrator.h"

void UserRegistrator::RegisterUser(CashOperator &cash_operator,
                                   UserIdentifier &user_identifier) {
  set_is_correct_registration(false);

  registation_messenger_.ShowRegistrationScreen();

  EnterLogin(user_identifier);
  if (user_identifier.IsNormalLogin()) {
    EnterPassword(user_identifier);
    if (user_identifier.IsNormalPass()) {
      notifier_.NoticeAboutSuccessfulRegistration();
      AssignInitialValues(cash_operator);
      set_is_correct_registration(true);
    } else {
      notifier_.NoticeAboutIncorrectFormatPasswordMessage();
    }
  } else {
    notifier_.NoticeAboutIncorrectLogin();
  }
}

bool UserRegistrator::IsCorrectRegistration() {
  return is_correct_registration_;
}

void UserRegistrator::EnterLogin(UserIdentifier &user_identifier) {
  user_identifier.SetLogin(provider_.GetLoginFromUser());
}

void UserRegistrator::EnterPassword(UserIdentifier &user_identifier) {
  user_identifier.SetPassword(provider_.GetPasswordFromUser());
}

void UserRegistrator::set_is_correct_registration(
    bool is_correct_registration) {
  is_correct_registration_ = is_correct_registration;
}

void UserRegistrator::AssignInitialValues(CashOperator &cash_operator) {
  cash_operator.SetCredit(0);
  cash_operator.SetMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
}
