#ifndef STRETCHER_H
#define STRETCHER_H

#include <QRect>

#include <conversion_factor.h>
#include <delta_size.h>

class Stretcher {
 public:
  void ComputeStretching(const QRect& initial_position);

  void SetStretchFactor(const ConversionFactor& stretch_factor);
  void SetStretchSide(unsigned int stretch_side);

  void SetDeltaSize(const DeltaSize& delta_size);

  int XPos() const;
  int YPos() const;
  int Width() const;
  int Height() const;

 private:
  DeltaSize delta_size_;
  ConversionFactor stretch_factor_;

  unsigned int stretch_side_ = 0;

  int x_pos_ = 0;
  int y_pos_ = 0;
  int width_ = 0;
  int height_ = 0;
};

#endif  // STRETCHER_H
