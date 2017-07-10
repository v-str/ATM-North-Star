#ifndef V_GROUP_COMPOSER_H
#define V_GROUP_COMPOSER_H

#include <QRect>
#include <QVector>

#include <conversion_factor.h>
#include <delta_size.h>

class QWidget;

class VGroupComposer {
 public:
  void SetDeltaSize(const DeltaSize& delta_size);

  void SetInitialGroupGeometry(const QVector<QRect>& widget_vector);
  void ScaleVGroup(QVector<QWidget*> scale_vector);

  void SetStretchFactor(double x_stretch_factor, double y_stretch_factor);
  void SetWidgetInterval(int widget_interval);

 private:
  void ComputeElementPosition(QWidget* current_widget,
                              QWidget* previous_widget);
  void ComputeElementSize(int element_number);
  void ComputeHeadGroupGeometry(QWidget* widget);

  QVector<QRect> geometry_vector_;

  DeltaSize delta_size_;
  ConversionFactor stretch_factor_;
  QRect geometry_;

  int widget_interval_ = 10;
};

#endif  // V_GROUP_COMPOSER_H
