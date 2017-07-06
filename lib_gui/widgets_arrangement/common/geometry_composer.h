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
  void SetShiftSide(unsigned int shift_side);
  void SetStretchSide(unsigned int stretch_side);

 private:
  void ComputeShifting(const QRect& initial_position,
                       unsigned int manipulation_flag);
  void ComputeStretching(const QRect& initial_position,
                         unsigned int manipulation_flag);

  void SetModifiedPosition(int x, int y, int width, int height);

  DeltaSize delta_size_;

  ConversionFactor stretch_factor_;
  ConversionFactor shift_factor_;

  QPoint shift_position_;
  QRect stretch_position_;

  QRect modified_position_;

  unsigned int shift_side_;
  unsigned int stretch_side_;
};

#endif  // GEOMETRY_COMPOSER_H
