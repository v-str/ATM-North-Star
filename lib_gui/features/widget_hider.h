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

 signals:
  void IsAlreadyHidden();

 public slots:
  void Hide(const QRect& geometry);
  void AnimationTimeOut();

 private:
  void SetStartHideValue(const QRect& start_value);
  void SetEndHideValue(const QRect& end_value);

  QPropertyAnimation* hide_animation_ = nullptr;
};

#endif  // WIDGET_HIDER_H
