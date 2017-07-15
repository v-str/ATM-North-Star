#include <shifter.h>

#include <QRect>

#include <side.h>

void Shifter::ComputeShifting(const QRect& initial_position) {
  x_pos_ = initial_position.x();
  y_pos_ = initial_position.y();

  if (shift_side_ & Side::kLeft) {
    x_pos_ -= (shift_factor_.XAxisFactor() * delta_size_.Width());
    if (is_center_) {
      x_pos_ += (stretch_factor_.XAxisFactor() * delta_size_.Width()) / 2;
    }
  }
  if (shift_side_ & Side::kRight) {
    x_pos_ += (shift_factor_.XAxisFactor() * delta_size_.Width());
    if (is_center_) {
      x_pos_ -= (stretch_factor_.XAxisFactor() * delta_size_.Width()) / 2;
    }
  }
  if (shift_side_ & Side::kUp) {
    y_pos_ -= (shift_factor_.YAxisFactor() * delta_size_.Height());
    if (is_center_) {
      y_pos_ += (stretch_factor_.YAxisFactor() * delta_size_.Height()) / 2;
    }
  }
  if (shift_side_ & Side::kDown) {
    y_pos_ += (shift_factor_.YAxisFactor() * delta_size_.Height());
    if (is_center_) {
      y_pos_ -= (stretch_factor_.YAxisFactor() * delta_size_.Height()) / 2;
    }
  }
}

void Shifter::SetShiftFactor(const ConversionFactor& shift_factor) {
  shift_factor_ = shift_factor;
}

void Shifter::SetshiftSide(unsigned int shift_side) {
  shift_side_ = shift_side;
}

void Shifter::SetStretchFactor(const ConversionFactor& stretch_factor) {
  stretch_factor_ = stretch_factor;
}

void Shifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void Shifter::SetCenter(bool is_center) { is_center_ = is_center; }

int Shifter::XPos() const { return x_pos_; }

int Shifter::YPOs() const { return y_pos_; }
