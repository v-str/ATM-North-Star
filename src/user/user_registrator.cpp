#include "user_registrator.h"

void UserRegistrator::Register(CashOperator &cash_operator,
                               UserIdentifier &user_identifier) {
  registation_messenger_.ShowRegistrationScreen();
  registation_messenger_.ShowInitialLoginText();
  user_identifier.EnterLogin();
  if (!user_identifier.IsNormalLogin()) {
    notifier_.NoticeAboutIncorrectLogin();
  } else {
    registation_messenger_.ShowInitialPasswordText();
    user_identifier.EnterPassword();
    if (!user_identifier.IsNormalPass()) {
      notifier_.NoticeAboutIncorrectFormatPasswordMessage();
    } else {
      notifier_.NoticeAboutSuccessfulRegistration();
      cash_operator.SetCredit(0);
      cash_operator.SetMonthlyPayment(0.0);
      cash_operator.SetAmountOfCreditMonth(0);
    }
  }
}
