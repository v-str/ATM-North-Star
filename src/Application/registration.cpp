#include "registration.h"

void Registration::RegisterUser(CashOperator &cash_operator,
                                UserIdentifier &user_identifier) {
  set_is_correct_registration(false);

  registation_messenger_.ShowRegistrationScreen();

  EnterLogin(user_identifier);
  if (user_identifier.IsNormalLogin()) {
    EnterPassword(user_identifier);
    if (user_identifier.IsNormalPass()) {
      notice_messenger_.ShowAcceptableMessageFrame();
      AssignInitialValues(cash_operator);
      set_is_correct_registration(true);
    } else {
      notifier_.NoticeAboutIncorrectFormatPasswordMessage();
    }
  } else {
    notifier_.NoticeAboutIncorrectLogin();
  }
}

bool Registration::IsCorrectRegistration() { return correct_registration_; }

void Registration::EnterLogin(UserIdentifier &user_identifier) {
  user_identifier.SetLogin(provider_.GetLoginFromUser());
}

void Registration::EnterPassword(UserIdentifier &user_identifier) {
  user_identifier.SetPassword(provider_.GetPasswordFromUser());
}

void Registration::set_is_correct_registration(bool correct_registration) {
  correct_registration_ = correct_registration;
}

void Registration::AssignInitialValues(CashOperator &cash_operator) {
  cash_operator.SetCredit(0);
  cash_operator.SetMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
}
