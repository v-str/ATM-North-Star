#ifndef FRAME_ANIMATOR_H
#define FRAME_ANIMATOR_H

#include <QObject>

class QPropertyAnimation;
class QWidget;
class QEasingCurve;
class QRect;

class FrameAnimator : public QObject {
  Q_OBJECT
 public:
  explicit FrameAnimator(QWidget* parent = nullptr);
  ~FrameAnimator();

  void SetWidgetForAnimation(QWidget* widget);
  void SetAnimationCurve(QEasingCurve& animation_curve);
  void SetDuration(unsigned int animation_duration_msec);
  void AnimationDirection(unsigned int animation_direction);

 public slots:
  void EndAnimation();

 signals:
  void AnimationComplete();

 protected:
  virtual void SetStartAnimationGeometry(QRect& start_geometry) = 0;
  virtual void SetEndAnimationGeometry(QRect& end_geometry) = 0;

  QPropertyAnimation* PropertyAnimation() const;

 private:
  int CheckOnPositiveValue(int value);

  QPropertyAnimation* property_animation_ = nullptr;

  int animation_direction_ = 4;
  int animation_duration_msec_ = 500;
};

#endif  // FRAME_ANIMATOR_H
