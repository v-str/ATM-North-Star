#ifndef WIDGET_HIDER_H
#define WIDGET_HIDER_H

#include <QObject>

class QPropertyAnimation;
class QWidget;
class QRect;

class WidgetHider : public QObject {
  Q_OBJECT
 public:
  ~WidgetHider();

  void SetWidgetForHideAnimation(QWidget* widget);
  void SetHideDirection(unsigned int hide_direction);

  bool IsHidden() const;

 public slots:
  void Hide(const QRect& geometry);
  void AnimationTimeOut();

 signals:
  void IsAlreadyHidden();

 private:
  void SetStartHideValue(const QRect& start_value);
  void SetEndHideValue(const QRect& end_value);

  QPropertyAnimation* hide_animation_ = nullptr;

  bool widget_is_hidden_ = false;

  unsigned int hide_direction_ = 4;
};

#endif  // WIDGET_HIDER_H
