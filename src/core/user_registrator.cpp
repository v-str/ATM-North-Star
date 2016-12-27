#include "user_registrator.h"

void UserRegistrator::RegisterUser(AtmUser &atm_user) {
  set_is_correct_registration(false);

  registation_messenger_.ShowRegistrationScreen();

  EnterLogin(atm_user);
  if (atm_user.IsNormalLogin()) {
    EnterPassword(atm_user);
    if (atm_user.IsNormalPass()) {
      notice_messenger_.ShowAcceptableMessageFrame();
      AssignInitialValues(atm_user);
      set_is_correct_registration(true);
    } else {
      notice_messenger_.ShowIncorrectFormatPassword();
    }
  } else {
    notice_messenger_.ShowIncorrectLoginFrame();
  }
}

bool UserRegistrator::IsCorrectRegistration() const {
  return correct_registration_;
}

void UserRegistrator::EnterLogin(AtmUser &atm_user) {
  identification_messenger_.ShowInitialLoginText();
  atm_user.set_login(provider_.GetLoginFromUser());
}

void UserRegistrator::EnterPassword(AtmUser &atm_user) {
  identification_messenger_.ShowInitialPasswordText();
  atm_user.set_password(provider_.GetPasswordFromUser());
}

void UserRegistrator::set_is_correct_registration(bool correct_registration) {
  correct_registration_ = correct_registration;
}

void UserRegistrator::AssignInitialValues(AtmUser &atm_user) {
  atm_user.set_cash(0);
  atm_user.set_credit(0);
  atm_user.set_monthly_payment(0.0);
  atm_user.set_amount_of_credit_month(0);
}
