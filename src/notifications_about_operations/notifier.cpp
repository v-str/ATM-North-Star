#include "notifier.h"

Notifier::Notifier() {}

void Notifier::NoticeAboutSuccessfulRegistration(
    CashOperator &cash_operator) const {
  notice_messenger_.ShowAcceptableMessageFrame();
  cash_operator.SetCredit(0);
  cash_operator.SetMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
}

void Notifier::NoticeAboutIncorrectLogin() const {
  notice_messenger_.ShowIncorrectLoginFrame();
}

void Notifier::NoticeAboutIncorrectFormatPasswordMessage() const {
  notice_messenger_.ShowIncorrectFormatPassword();
}

void Notifier::NoticeAboutIncorrectDataMessage() const {
  notice_messenger_.ShowIncorrectData();
}

void Notifier::NoticeAboutIncorrectSum() const {
  notice_messenger_.ShowIncorrectSum();
}

void Notifier::NoticeUnacceptableWithdrawal(int amount_of_cash,
                                            int incorrect_sum) const {
  notice_messenger_.ShowUnacceptableWithdrawal(incorrect_sum, amount_of_cash);
}

void Notifier::ShowIncorrectDataMessage() const {
  notice_messenger_.ShowError();
}

void Notifier::NoticeAboutIncorrectMonths() const {
  notice_messenger_.ShowIncorrectfMonths();
}
