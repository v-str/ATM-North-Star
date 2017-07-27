#include <frame_animator.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QWidget>

FrameAnimator::FrameAnimator(QWidget* parent)
    : QObject(parent), property_animation_(new QPropertyAnimation) {}

FrameAnimator::~FrameAnimator() { delete property_animation_; }

void FrameAnimator::SetWidgetForAnimation(QWidget* widget) {
  property_animation_->setTargetObject(widget);
}

void FrameAnimator::SetAnimationCurve(QEasingCurve& animation_curve) {
  property_animation_->setEasingCurve(animation_curve);
}

void FrameAnimator::AnimationDirection(unsigned int animation_direction) {
  animation_direction_ = CheckOnPositiveValue(animation_direction);
}

void FrameAnimator::EndAnimation() { emit AnimationComplete(); }

void FrameAnimator::SetDuration(unsigned int animation_duration_msec) {
  animation_duration_msec_ = CheckOnPositiveValue(animation_duration_msec);
}

int FrameAnimator::CheckOnPositiveValue(int value) {
  if (value < 0) {
    value = 0;
  }
  return value;
}

QPropertyAnimation* FrameAnimator::PropertyAnimation() const {
  return property_animation_;
}
