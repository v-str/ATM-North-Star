#include <abstract_widget_animation.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QWidget>

AbstractWidgetAnimation::AbstractWidgetAnimation(QWidget* parent)
    : QObject(parent), property_animation_(new QPropertyAnimation) {}

AbstractWidgetAnimation::~AbstractWidgetAnimation() {
  delete property_animation_;
}

void AbstractWidgetAnimation::SetWidgetForAnimation(QWidget* widget) {
  property_animation_->setTargetObject(widget);
}

void AbstractWidgetAnimation::SetAnimationCurve(QEasingCurve& animation_curve) {
  property_animation_->setEasingCurve(animation_curve);
}

void AbstractWidgetAnimation::AnimationDirection(
    unsigned int animation_direction) {
  animation_direction_ = CheckOnPositiveValue(animation_direction);
}

void AbstractWidgetAnimation::EndAnimation() { emit AnimationComplete(); }

void AbstractWidgetAnimation::SetDuration(unsigned int animation_duration_msec) {
  animation_duration_msec_ = CheckOnPositiveValue(animation_duration_msec);
}

int AbstractWidgetAnimation::CheckOnPositiveValue(int value) {
  if (value < 0) {
    value = 0;
  }
  return value;
}

QPropertyAnimation* AbstractWidgetAnimation::PropertyAnimation() const {
  return property_animation_;
}
