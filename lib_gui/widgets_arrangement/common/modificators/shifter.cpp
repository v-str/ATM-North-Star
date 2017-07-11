#include <shifter.h>

#include <QRect>

Shifter::Shifter() {}

void Shifter::ShiftLeft(QRect* rect) {
  rect->setX(rect->x() - shift_factor_.XAxisFactor() * delta_size_.Width());
  if (is_center_) {
    rect->setX(rect->x() +
               (stretch_factor_.XAxisFactor() * delta_size_.Width()) / 2);
  }
}

void Shifter::SetShiftFactor(const ConversionFactor& shift_factor) {
  shift_factor_ = shift_factor;
}

void Shifter::SetStretchFactor(const ConversionFactor& stretch_factor) {
  stretch_factor_ = stretch_factor;
}

void Shifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void Shifter::SetCenter(bool is_center) { is_center_ = is_center; }
