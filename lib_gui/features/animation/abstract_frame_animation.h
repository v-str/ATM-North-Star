#ifndef ABSTRACT_FRAME_ANIMATION_H
#define ABSTRACT_FRAME_ANIMATION_H

#include <QObject>

class QPropertyAnimation;
class QWidget;
class QEasingCurve;

class AbstractFrameAnimation : public QObject {
  Q_OBJECT
 public:
  explicit AbstractFrameAnimation(QWidget* parent = nullptr);
  ~AbstractFrameAnimation();

  void SetWidgetForAnimation(QWidget* widget);
  void SetAnimationCurve(QEasingCurve& animation_curve);
  void SetDuration(unsigned int animation_duration_msec);
  void AnimationDirection(unsigned int animation_direction);

 signals:
  void AnimationComplete();

 protected:
  int CheckOnPositiveValue(int value);

  QPropertyAnimation* PropertyAnimation() const;

 private:
  QPropertyAnimation* property_animation_ = nullptr;

  int animation_direction_ = 4;
  int animation_duration_msec_ = 500;
};

#endif  // ABSTRACT_FRAME_ANIMATION_H
