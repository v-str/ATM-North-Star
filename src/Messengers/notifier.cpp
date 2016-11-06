#include "notifier.h"

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
