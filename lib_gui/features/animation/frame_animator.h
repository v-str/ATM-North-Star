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
  enum AnimationType { kHideFrame, kExtrudeFrame };

  explicit FrameAnimator(QWidget* parent = nullptr);
  ~FrameAnimator();

  void SetWidgetForAnimation(
      QWidget* widget,
      AnimationType animation_type = AnimationType::kHideFrame);

  void SetAnimationCurve(QEasingCurve animation_curve);
  void SetDuration(unsigned int animation_duration_msec);
  void SetAnimationDirection(unsigned int animation_direction);

 public slots:
  void HideFrame(const QRect& geometry);
  void ExtrudeFrame(const QRect& geometry);

  void StartAnimation();
  void EndAnimation();

 signals:
  void AnimationComplete();

 private:
  void SetAnimationGeometry(const QRect& geometry);
  void SetStartAnimationGeometry(const QRect& start_geometry);
  void SetEndAnimationGeometry(const QRect& end_geometry);

  void SetStartHideGeometry(const QRect& start_geometry);
  void SetEndHideGeometry(const QRect& end_geometry);
  void SetStartExtrudeGeometry(const QRect& start_geometry);
  void SetEndExtrudeGeometry(const QRect& end_geometry);

  int CheckOnPositiveValue(int value);

  QPropertyAnimation* animation_ = nullptr;
  AnimationType animation_type_;

  int animation_direction_ = 4;
  int animation_duration_msec_ = 500;
};

#endif  // FRAME_ANIMATOR_H
