#ifndef GEOMETRY_COMPOSER_H
#define GEOMETRY_COMPOSER_H

#include <QPoint>
#include <QRect>

#include <conversion_factor.h>
#include <delta_size.h>

class QWidget;

class GeometryComposer {
 public:
  enum TransformationType { kShift, kStretch };

  void SetDeltaSize(const DeltaSize& delta_size);

  void Transform(const ConversionFactor& conversion_factor,
                 const QRect& initial_position,
                 TransformationType type,
                 unsigned int manipulation_flag,
                 QWidget* widget);

 private:
  void ComputeShifting(const QRect& initial_position,
                       unsigned int manipulation_flag);
  void ComputeStretching(const QRect& initial_position,
                         unsigned int manipulation_flag);

  DeltaSize delta_size_;
  ConversionFactor conversion_factor_;
  QPoint shift_position_;
  QRect stretch_position_;
};

#endif  // GEOMETRY_COMPOSER_H
