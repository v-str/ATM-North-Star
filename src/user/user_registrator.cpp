#include "user_registrator.h"

void UserRegistrator::Register(CashOperator &cash_operator,
                               UserIdentifier &user_identifier) {
  registation_messenger_.ShowRegistrationScreen();
  // user_messenger_.ShowRegistrationScreen();
  user_messenger_.ShowInitialLoginText();
  user_identifier.EnterLogin();
  if (!user_identifier.IsNormalLogin()) {
    error_message_.NoticeAboutIncorrectLogin();
  } else {
    user_messenger_.ShowInitialPasswordText();
    user_identifier.EnterPassword();
    if (!user_identifier_.IsNormalPass()) {
      error_message_.NoticeAboutIncorrectFormatPasswordMessage();
    } else {
      successful_action_.NoticeAboutSuccessfulRegistration(cash_operator);
    }
  }
}
