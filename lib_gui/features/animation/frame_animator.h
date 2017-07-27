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
  void HideFrame(const QRect& geometry);
  void EndAnimation();

 signals:
  void AnimationComplete();

 private:
  void SetStartAnimationGeometry(const QRect& start_geometry);
  void SetEndAnimationGeometry(const QRect& end_geometry);

  int CheckOnPositiveValue(int value);

  QPropertyAnimation* animation_ = nullptr;

  int animation_direction_ = 4;
  int animation_duration_msec_ = 500;
};

#endif  // FRAME_ANIMATOR_H
