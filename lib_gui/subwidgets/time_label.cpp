#include <time_label.h>

#include <QTimer>

#include <timedate_changer.h>

TimeLabel::TimeLabel(QWidget* parent)
    : QLabel(parent), timer_(new QTimer(this)) {
  SetDefaultSettings();
}

TimeLabel::~TimeLabel() { delete timer_; }

void TimeLabel::UpdateTime() { TimeDateChanger::ChangeTime(this); }

void TimeLabel::resizeEvent(QResizeEvent* event) {}

void TimeLabel::SetDefaultSettings() {
  setAlignment(Qt::AlignCenter);
  timer_->start(kOneSecond);
  connect(timer_, SIGNAL(timeout()), SLOT(UpdateTime()));
}
