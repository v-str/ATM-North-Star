#include "notifier.h"

void Notifier::ShowIncorrectDataMessage() const {
  notice_messenger_.ShowError();
}

void Notifier::NoticeAboutIncorrectMonths() const {
  notice_messenger_.ShowIncorrectfMonths();
}
