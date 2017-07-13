#ifndef GEOMETRY_COMPOSER_H
#define GEOMETRY_COMPOSER_H

#include <QRect>

#include <conversion_factor.h>
#include <delta_size.h>

#include <shifter.h>
#include <stretcher.h>

class QWidget;

class GeometryComposer {
 public:
  enum TransformationType { kShift, kStretch, kScale };

  void ComposeGeometry(const QRect& initial_position, QWidget* widget);

  void SetDeltaSize(const DeltaSize& delta_size);
  void SetParentGeometry(const QRect& parent_geometry);

  void SetShiftFactor(double x_shift_factor, double y_shift_factor);
  void SetShiftSide(unsigned int shift_side);
  void SetStretchFactor(double x_stretch_factor, double y_stretch_factor);
  void SetStretchSide(unsigned int stretch_side);

  void SetTransformationType(TransformationType type);
  void KeepCenter(bool is_center);

 private:
  void ComputeShifting(const QRect& position);
  void ComputeStretching(const QRect& position);

  void SetModifiedPosition(int x, int y, int width, int height);

  TransformationType type_;

  QRect modified_widget_geometry_;
  QRect parent_geometry_;

  Shifter shifter_;
  Stretcher stretcher_;
};

#endif  // GEOMETRY_COMPOSER_H
