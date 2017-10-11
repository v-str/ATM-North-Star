#ifndef SHIFTER_H
#define SHIFTER_H

#include <QRect>

#include <conversion_factor.h>
#include <delta_size.h>

class Shifter {
 public:
  void ComputeShifting(const QRect& initial_position);

  void SetShiftFactor(const ConversionFactor& shift_factor);
  void SetShiftSide(unsigned int shift_side);

  void SetStretchFactor(const ConversionFactor& stretch_factor);

  void SetDeltaSize(const DeltaSize& delta_size);
  void SetCenter(bool is_center);

  int XPos() const;
  int YPOs() const;

 private:
  DeltaSize delta_size_;
  ConversionFactor shift_factor_;
  ConversionFactor stretch_factor_;

  unsigned int shift_side_ = 0;

  int x_pos_ = 0;
  int y_pos_ = 0;

  bool is_center_ = false;
};

#endif  // SHIFTER_H
