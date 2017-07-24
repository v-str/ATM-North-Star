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
  void SetAnimationDuration(unsigned int animation_duration_msec);

 public slots:
  void Extrude(const QRect& geometry);
  void StartAnimation();
  void EndAnimation();

 signals:
  void AlreadyExtruded();

 private:
  void SetStartExtrudeAnimation(const QRect& start_geometry);
  void SetEndExtrudeAnimation(const QRect& end_geometry);

  QPropertyAnimation* extrude_animation_ = nullptr;

  QRect start_widget_geometry_;

  unsigned int extrude_direction_ = 4;
  unsigned int animation_duration_msec_ = 500;
};

#endif  // WIDGET_EXTRUDER_H
