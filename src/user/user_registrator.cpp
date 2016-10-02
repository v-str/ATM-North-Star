#include "user_registrator.h"

void UserRegistrator::RegisterUser(CashOperator &cash_operator,
                                   UserIdentifier &user_identifier) {
  is_correct_registration_ = false;

  registation_messenger_.ShowRegistrationScreen();

  EnterLogin(user_identifier);
  if (user_identifier.IsNormalLogin()) {
    EnterPassword(user_identifier);
    if (user_identifier.IsNormalPass()) {
      notifier_.NoticeAboutSuccessfulRegistration();
      cash_operator.SetCredit(0);
      cash_operator.SetMonthlyPayment(0.0);
      cash_operator.SetAmountOfCreditMonth(0);
      is_correct_registration_ = true;
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
  registation_messenger_.ShowInitialLoginText();
  user_identifier.EnterLogin();
}

void UserRegistrator::EnterPassword(UserIdentifier &user_identifier) {
  registation_messenger_.ShowInitialPasswordText();
  user_identifier.EnterPassword();
}
