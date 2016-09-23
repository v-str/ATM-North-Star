#include "notice_about_error.h"

NoticeAboutError::NoticeAboutError() {}

void NoticeAboutError::NoticeAboutIncorrectLogin() const {
  notice_messenger_.ShowIncorrectLoginFrame();
}

void NoticeAboutError::NoticeAboutIncorrectFormatPasswordMessage() const {
  notice_messenger_.ShowIncorrectFormatPassword();
}

void NoticeAboutError::NoticeAboutIncorrectDataMessage() const {
  notice_messenger_.ShowIncorrectData();
}

void NoticeAboutError::NoticeAboutIncorrectSum() const {
  notice_messenger_.ShowIncorrectSum();
}

void NoticeAboutError::NoticeUnacceptableWithdrawal(int amount_of_cash,
                                                    int incorrect_sum) const {
  notice_messenger_.ShowUnacceptableWithdrawal(incorrect_sum, amount_of_cash);
}

bool NoticeAboutError::ShowIncorrectDataMessage() {
  notice_messenger_.ShowError();
  return true;
}
