#include "notifier.h"

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
