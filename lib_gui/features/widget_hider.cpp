#include <widget_hider.h>

#include <QApplication>
#include <QDesktopWidget>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QRect>
#include <QTimer>
#include <QWidget>

WidgetHider::~WidgetHider() { delete hide_animation_; }

void WidgetHider::SetWidgetForHideAnimation(QWidget* widget) {
  if (hide_animation_ != nullptr) {
    delete hide_animation_;
  }

  hide_animation_ = new QPropertyAnimation(widget, "geometry");
  hide_animation_->setDuration(500);
  hide_animation_->setEasingCurve(QEasingCurve::OutCirc);
}

void WidgetHider::SetHideDirection(unsigned int hide_direction) {
  hide_direction_ = hide_direction;
}

bool WidgetHider::IsHidden() { return widget_is_hidden_; }

void WidgetHider::Hide(const QRect& geometry) {
  SetStartHideValue(geometry);
  SetEndHideValue(geometry);
  hide_animation_->start();
  QTimer::singleShot(500, this, SLOT(AnimationTimeOut()));
}

void WidgetHider::AnimationTimeOut() {
  widget_is_hidden_ = true;
  emit IsAlreadyHidden();
}

void WidgetHider::SetStartHideValue(const QRect& start_value) {
  hide_animation_->setStartValue(start_value);
}

void WidgetHider::SetEndHideValue(const QRect& end_value) {
  int x = end_value.x();
  int y = end_value.y();

  hide_animation_->setEndValue(QRect(x, y, end_value.width(), 0));
}
