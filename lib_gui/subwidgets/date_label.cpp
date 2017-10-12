#include <date_label.h>

#include <QTimer>

#include <timedate_changer.h>

DateLabel::DateLabel(QWidget *parent)
    : QLabel(parent), timer_(new QTimer(this)) {
  setAlignment(Qt::AlignCenter);
  timer_->start(kOneSecond);
  connect(timer_, SIGNAL(timeout()), SLOT(UpdateTime()));
}

DateLabel::~DateLabel() { delete timer_; }

void DateLabel::UpdateTime() { TimeDateChanger::ChangeDate(this); }
