#ifndef SHIFTER_H
#define SHIFTER_H

#include <QRect>

#include <conversion_factor.h>
#include <delta_size.h>

class Shifter {
 public:
  Shifter();

  void ShiftLeft(QRect* rect);
  void ShiftRight(QRect* rect);

  void SetShiftFactor(const ConversionFactor& shift_factor);
  void SetStretchFactor(const ConversionFactor& stretch_factor);

  void SetDeltaSize(const DeltaSize& delta_size);
  void SetCenter(bool is_center);

 private:
  QRect temp_rect_;

  DeltaSize delta_size_;
  ConversionFactor shift_factor_;
  ConversionFactor stretch_factor_;

  bool is_center_ = false;
};

#endif  // SHIFTER_H
