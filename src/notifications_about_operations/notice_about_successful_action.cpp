#include "notice_about_successful_action.h"

void NoticeAboutSuccessfulAction::NoticeAboutSuccessfulRegistration(
    CashOperator &cash_operator) const {
  notice_messenger_.ShowAcceptableMessageInFrame();
  cash_operator.SetCredit(0);
  cash_operator.SetMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
}
