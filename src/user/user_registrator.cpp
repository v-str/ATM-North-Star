#include "user_registrator.h"

void UserRegistrator::RegisterUser(CashOperator &cash_operator,
                                   UserIdentifier &user_identifier) {
  registation_messenger_.ShowRegistrationScreen();

  EnterLogin(user_identifier);
  if (IsNormalLogin(user_identifier)) {
    EnterPassword(user_identifier);
    if (IsNormalPassword(user_identifier)) {
      notifier_.NoticeAboutSuccessfulRegistration();
      cash_operator.SetCredit(0);
      cash_operator.SetMonthlyPayment(0.0);
      cash_operator.SetAmountOfCreditMonth(0);
    }
  }
}

bool UserRegistrator::IsNormalRegistration() { return correct_registration_; }

void UserRegistrator::EnterLogin(UserIdentifier &user_identifier) {
  registation_messenger_.ShowInitialLoginText();
  user_identifier.EnterLogin();
}

bool UserRegistrator::IsNormalLogin(UserIdentifier &user_identifier) {
  if (!user_identifier.IsNormalLogin()) {
    notifier_.NoticeAboutIncorrectLogin();
    return correct_registration_ = false;
  }
  return correct_registration_ = true;
}

void UserRegistrator::EnterPassword(UserIdentifier &user_identifier) {
  registation_messenger_.ShowInitialPasswordText();
  user_identifier.EnterPassword();
}

bool UserRegistrator::IsNormalPassword(UserIdentifier &user_identifier) {
  if (!user_identifier.IsNormalPass()) {
    notifier_.NoticeAboutIncorrectFormatPasswordMessage();
    return correct_registration_ = false;
  }
  return correct_registration_ = true;
}
