#include <delta_size.h>

DeltaSize::DeltaSize(int delta_width, int delta_height)
    : delta_width_(delta_width), delta_height_(delta_height) {}

void DeltaSize::SetDeltaWidth(int delta_width) { delta_width_ = delta_width; }

void DeltaSize::SetDeltaHeight(int delta_height) {
  delta_height_ = delta_height;
}

int DeltaSize::DeltaWidth() const { return delta_width_; }

int DeltaSize::DeltaHeight() const { return delta_height_; }
