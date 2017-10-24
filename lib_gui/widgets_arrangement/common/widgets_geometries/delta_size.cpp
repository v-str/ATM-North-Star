#include <delta_size.h>

DeltaSize::DeltaSize() {}

DeltaSize::DeltaSize(int width, int height) : width_(width), height_(height) {}

DeltaSize DeltaSize::operator-(const DeltaSize& delta_size) {
  width_ -= delta_size.Width();
  height_ -= delta_size.Height();

  return DeltaSize(width_, height_);
}

void DeltaSize::SetDeltaSize(const DeltaSize& delta_size) {
  width_ = delta_size.Width();
  height_ = delta_size.Height();
}

void DeltaSize::SetWidth(int delta_width) { width_ = delta_width; }

void DeltaSize::SetHeight(int delta_height) { height_ = delta_height; }

int DeltaSize::Width() const { return width_; }

int DeltaSize::Height() const { return height_; }
