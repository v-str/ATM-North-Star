#include <time_label.h>

#include <QTimer>

#include <geometry_composer.h>
#include <side.h>
#include <timedate_changer.h>

TimeLabel::TimeLabel(QLabel* parent)
    : QLabel(parent),
      timer_(new QTimer(this)),
      composer_(new GeometryComposer) {
  SetDefaultSettings();
}

TimeLabel::~TimeLabel() {
  delete timer_;
  delete composer_;
}

void TimeLabel::UpdateTime() { TimeDateChanger::ChangeTime(this); }

void TimeLabel::resizeEvent(QResizeEvent* event) {}

void TimeLabel::SetDefaultSettings() {
  setAlignment(Qt::AlignCenter);
  timer_->start(kOneSecond);
  connect(timer_, SIGNAL(timeout()), SLOT(UpdateTime()));
}
