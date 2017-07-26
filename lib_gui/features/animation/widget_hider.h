#ifndef WIDGET_HIDER_H
#define WIDGET_HIDER_H

#include <QObject>

class QPropertyAnimation;
class QWidget;
class QRect;
class QEasingCurve;

class WidgetHider : public QObject {
  Q_OBJECT
 public:
  ~WidgetHider();

  void SetWidgetForHideAnimation(QWidget* widget);
  void SetHideDirection(unsigned int hide_direction);
  void SetAnimationDuration(unsigned int animation_duration_msec);
  void SetAnimationCurve(QEasingCurve curve);

  unsigned int AnimationDurationMSec() const;

 public slots:
  void Hide(const QRect& geometry);
  void EndAnimation();

 signals:
  void IsAlreadyHidden();

 private:
  void SetStartHideValue(const QRect& start_geometry);
  void SetEndHideValue(const QRect& end_geometry);

  QPropertyAnimation* hide_animation_ = nullptr;

  unsigned int hide_direction_ = 4;
  unsigned int animation_duration_msec_ = 500;
};

#endif  // WIDGET_HIDER_H
