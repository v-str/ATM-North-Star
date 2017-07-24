#include <widget_hider.h>

#include <QApplication>
#include <QDesktopWidget>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QRect>
#include <QTimer>
#include <QWidget>

#include <side.h>

WidgetHider::~WidgetHider() { delete hide_animation_; }

void WidgetHider::SetWidgetForHideAnimation(QWidget* widget) {
  if (hide_animation_ != nullptr) {
    delete hide_animation_;
  }

  hide_animation_ = new QPropertyAnimation(widget, "geometry");
  hide_animation_->setDuration(animation_duration_msec_);
  hide_animation_->setEasingCurve(QEasingCurve::OutCirc);
}

void WidgetHider::SetHideDirection(unsigned int hide_direction) {
  hide_direction_ = hide_direction;
}

void WidgetHider::SetAnimationDuration(unsigned int animation_duration_msec) {
  animation_duration_msec_ = animation_duration_msec;
  hide_animation_->setDuration(animation_duration_msec_);
}

unsigned int WidgetHider::AnimationDurationMSec() const {
  return animation_duration_msec_;
}

void WidgetHider::Hide(const QRect& geometry) {
  SetStartHideValue(geometry);
  SetEndHideValue(geometry);
  hide_animation_->start();
  QTimer::singleShot(animation_duration_msec_, this, SLOT(EndAnimation()));
}

void WidgetHider::EndAnimation() { emit IsAlreadyHidden(); }

void WidgetHider::SetStartHideValue(const QRect& start_geometry) {
  hide_animation_->setStartValue(start_geometry);
}

void WidgetHider::SetEndHideValue(const QRect& end_geometry) {
  int x = end_geometry.x();
  int y = end_geometry.y();
  int width = end_geometry.width();
  int height = end_geometry.height();

  if (hide_direction_ & Side::kUp) {
    hide_animation_->setEndValue(QRect(x, y, width, 0));
    height = 0;
  }
  if (hide_direction_ & Side::kDown) {
    y += height;
    height = 0;
  }
  if (hide_direction_ & Side::kLeft) {
    width = 0;
  }
  if (hide_direction_ & Side::kRight) {
    x += width;
    width = 0;
  }

  hide_animation_->setEndValue(QRect(x, y, width, height));
}
