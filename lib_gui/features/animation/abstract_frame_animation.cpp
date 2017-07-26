#include <abstract_frame_animation.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QWidget>

AbstractFrameAnimation::AbstractFrameAnimation(QWidget* parent)
    : QObject(parent), property_animation_(new QPropertyAnimation) {}

AbstractFrameAnimation::~AbstractFrameAnimation() {
  delete property_animation_;
}

void AbstractFrameAnimation::SetWidgetForAnimation(QWidget* widget) {
  property_animation_->setTargetObject(widget);
}

void AbstractFrameAnimation::SetAnimationCurve(QEasingCurve& animation_curve) {
  property_animation_->setEasingCurve(animation_curve);
}

void AbstractFrameAnimation::AnimationDirection(
    unsigned int animation_direction) {
  animation_direction_ = CheckOnPositiveValue(animation_direction);
}

void AbstractFrameAnimation::SetDuration(unsigned int animation_duration_msec) {
  animation_duration_msec_ = CheckOnPositiveValue(animation_duration_msec);
}

int AbstractFrameAnimation::CheckOnPositiveValue(int value) {
  if (value < 0) {
    value = 0;
  }
  return value;
}

QPropertyAnimation* AbstractFrameAnimation::PropertyAnimation() const {
  return property_animation_;
}
