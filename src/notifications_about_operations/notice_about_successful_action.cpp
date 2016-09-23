#include "notice_about_successful_action.h"

const int kint_null = 0;
const int kdouble_null = 0.0;

void NoticeAboutSuccessfulAction::NoticeAboutSuccessfulRegistration(
    CashOperator &cash_operator) const {
  notice_messenger_.ShowAcceptableMessageInFrame();
  cash_operator.SetCredit(kint_null);
  cash_operator.SetMonthlyPayment(kdouble_null);
  cash_operator.SetAmountOfCreditMonth(kint_null);
}
