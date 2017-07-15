#ifndef V_GROUP_COMPOSER_H
#define V_GROUP_COMPOSER_H

#include <QRect>
#include <QVector>

#include <delta_size.h>
#include <geometry_composer.h>

class QWidget;

class VGroupComposer : public GeometryComposer {
 public:
  void SetInitialGroupGeometry(const QVector<QRect>& widget_vector);
  void ScaleVGroup(QVector<QWidget*> scale_vector);
  void SetWidgetInterval(int widget_interval);

 private:
  void ComputeElementGeometry(QWidget* previous_widget);

  void ComputeHeadGroupGeometry(QWidget* widget);

  QVector<QRect> geometry_vector_;

  QRect geometry_;

  int widget_interval_ = 10;
};

#endif  // V_GROUP_COMPOSER_H
