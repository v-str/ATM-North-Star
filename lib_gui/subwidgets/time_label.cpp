#include <time_label.h>

#include <QTimer>

#include <timedate_changer.h>

TimeLabel::TimeLabel(QLabel *parent)
    : QLabel(parent), timer_(new QTimer(this)) {
  timer_->start(kOneSecond);
  connect(timer_, SIGNAL(timeout()), SLOT(UpdateTime()));
}

TimeLabel::~TimeLabel() { delete timer_; }

void TimeLabel::UpdateTime() { TimeDateChanger::ChangeTime(this); }
