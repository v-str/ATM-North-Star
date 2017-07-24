#ifndef WIDGET_EXTRUDER_H
#define WIDGET_EXTRUDER_H

#include <QObject>
#include <QRect>

class QPropertyAnimation;
class QWidget;

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
  void SetStartExtrudeGeometry(const QRect& geometry);

  void SetStartExtrudeAnimation(const QRect& start_value);
  void SetEndExtrudeAnimation(const QRect& end_value);

  QPropertyAnimation* extrude_animation_ = nullptr;

  QRect start_widget_geometry_;

  bool is_widget_extruded_ = false;

  unsigned int extrude_direction_ = 4;
  unsigned int extrude_animation_msec_ = 500;
};

#endif  // WIDGET_EXTRUDER_H
