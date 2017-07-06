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

  void ComposeGeometry(const ConversionFactor& conversion_factor,
                       const QRect& initial_position,
                       TransformationType type,
                       unsigned int manipulation_flag,
                       QWidget* widget);

  void SetShiftFactor(double x_shift_factor, double y_shift_factor);
  void SetStretchFactor(double x_stretch_factor, double y_stretch_factor);

 private:
  void ComputeShifting(const QRect& initial_position,
                       unsigned int manipulation_flag);
  void ComputeStretching(const QRect& initial_position,
                         unsigned int manipulation_flag);

  void SetModifiedPosition(int x, int y, int width, int height);

  DeltaSize delta_size_;

  ConversionFactor conversion_factor_;
  ConversionFactor stretch_factor_;
  ConversionFactor shift_factor_;

  QPoint shift_position_;
  QRect stretch_position_;

  QRect modified_position_;
};

#endif  // GEOMETRY_COMPOSER_H
