#ifndef WIDGET_EXTRUDER_H
#define WIDGET_EXTRUDER_H

#include <QObject>

class QPropertyAnimation;
class QWidget;
class QRect;

class WidgetExtruder : public QObject {
  Q_OBJECT
 public:
  ~WidgetExtruder();

  void SetWidgetForExtrudeAnimaiton(QWidget* widget);
  void SetExtrudeDirection(unsigned int direction);

  bool IsExtruded() const;

 public slots:
  void Extrude(const QRect& geometry);
  void AnimationTimeOut();

 signals:
  void IsAlreadyExtruded();

 private:
  void SetStartExtrudeAnimation(const QRect& start_value);
  void SetEndExtrudeAnimation(const QRect& end_value);

  QPropertyAnimation* extrude_animation_ = nullptr;

  bool is_widget_extruded_ = false;

  unsigned int extrude_direction_ = 4;
};

#endif  // WIDGET_EXTRUDER_H
