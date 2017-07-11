#ifndef GEOMETRY_COMPOSER_H
#define GEOMETRY_COMPOSER_H

#include <QRect>

#include <conversion_factor.h>
#include <delta_size.h>
#include <shifter.h>

class QWidget;

class GeometryComposer {
 public:
  enum TransformationType { kShift, kStretch, kScale };

  void ComposeGeometry(const QRect& initial_position, QWidget* widget);

  void SetDeltaSize(const DeltaSize& delta_size);

  void SetShiftFactor(double x_shift_factor, double y_shift_factor);
  void SetShiftSide(unsigned int shift_side);
  void SetStretchFactor(double x_stretch_factor, double y_stretch_factor);
  void SetStretchSide(unsigned int stretch_side);

  void SetTransformationType(TransformationType type);
  void KeepCenter(bool is_center);

  DeltaSize GetDeltaSize() const;
  ConversionFactor ShiftFactor() const;
  ConversionFactor StretchFactor() const;

 private:
  void ComputeShifting(const QRect& position);
  void ComputeStretching(const QRect& position);

  void SetModifiedPosition(int x, int y, int width, int height);

  void RightShiftProcessing();

  void UpShiftProcessing();
  void DownShiftProcessing();

  DeltaSize delta_size_;

  TransformationType type_;
  ConversionFactor stretch_factor_;
  ConversionFactor shift_factor_;

  Shifter shifter_;

  QRect modified_widget_geometry_;

  unsigned int shift_side_ = 0;
  unsigned int stretch_side_ = 0;

  unsigned int x_pos_ = 0;
  unsigned int y_pos_ = 0;

  bool is_center_ = false;
};

#endif  // GEOMETRY_COMPOSER_H
