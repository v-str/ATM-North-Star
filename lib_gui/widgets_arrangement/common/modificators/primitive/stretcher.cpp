#include <stretcher.h>

#include <side.h>

void Stretcher::ComputeStretching(const QRect& initial_position) {
  x_pos_ = initial_position.x();
  y_pos_ = initial_position.y();
  width_ = initial_position.width();
  height_ = initial_position.height();

  if (stretch_side_ & Side::kLeft) {
    width_ += (stretch_factor_.XAxisFactor() * delta_size_.Width());
    x_pos_ -= (stretch_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (stretch_side_ & Side::kRight) {
    width_ += (stretch_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (stretch_side_ & Side::kDown) {
    height_ += (stretch_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (stretch_side_ & Side::kUp) {
    height_ += (stretch_factor_.YAxisFactor() * delta_size_.Height());
    y_pos_ -= (stretch_factor_.YAxisFactor() * delta_size_.Height());
  }
}

void Stretcher::SetStretchFactor(const ConversionFactor& stretch_factor) {
  stretch_factor_ = stretch_factor;
}

void Stretcher::SetStretchSide(unsigned int stretch_side) {
  stretch_side_ = stretch_side;
}

void Stretcher::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

int Stretcher::XPos() const { return x_pos_; }

int Stretcher::YPos() const { return y_pos_; }

int Stretcher::Width() const { return width_; }

int Stretcher::Height() const { return height_; }
