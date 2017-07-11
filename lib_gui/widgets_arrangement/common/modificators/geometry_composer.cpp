#include <geometry_composer.h>

#include <QWidget>

#include <side.h>

void GeometryComposer::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void GeometryComposer::ComposeGeometry(const QRect& initial_position,
                                       QWidget* widget) {
  switch (type_) {
    case kShift:
      ComputeShifting(initial_position);
      break;
    case kStretch:
      ComputeStretching(initial_position);
      break;
    case kScale:
      ComputeStretching(initial_position);
      ComputeShifting(modified_position_);
      break;
  }
  widget->setGeometry(modified_position_);
}

void GeometryComposer::SetShiftFactor(double x_shift_factor,
                                      double y_shift_factor) {
  shift_factor_.SetXFactor(x_shift_factor);
  shift_factor_.SetYFactor(y_shift_factor);
}

void GeometryComposer::SetStretchFactor(double x_stretch_factor,
                                        double y_stretch_factor) {
  stretch_factor_.SetXFactor(x_stretch_factor);
  stretch_factor_.SetYFactor(y_stretch_factor);
}

void GeometryComposer::SetShiftSide(unsigned int shift_side) {
  shift_side_ = shift_side;
}

void GeometryComposer::SetStretchSide(unsigned int stretch_side) {
  stretch_side_ = stretch_side;
}

void GeometryComposer::SetTransformationType(
    GeometryComposer::TransformationType type) {
  type_ = type;
}

void GeometryComposer::KeepCenter(bool is_center) { is_center_ = is_center; }

DeltaSize GeometryComposer::GetDeltaSize() const { return delta_size_; }

ConversionFactor GeometryComposer::ShiftFactor() const { return shift_factor_; }

ConversionFactor GeometryComposer::StretchFactor() const {
  return stretch_factor_;
}

void GeometryComposer::ComputeShifting(const QRect& position) {
  int x = position.x();
  int y = position.y();

  if (shift_side_ & Side::kLeft) {
    x -= (shift_factor_.XAxisFactor() * delta_size_.Width());
    if (is_center_) {
      x += (stretch_factor_.XAxisFactor() * delta_size_.Width()) / 2;
    }
  }
  if (shift_side_ & Side::kRight) {
    x += (shift_factor_.XAxisFactor() * delta_size_.Width());
    if (is_center_) {
      x -= (stretch_factor_.XAxisFactor() * delta_size_.Width()) / 2;
    }
  }
  if (shift_side_ & Side::kUp) {
    y -= (shift_factor_.YAxisFactor() * delta_size_.Height());
    if (is_center_) {
      y += (stretch_factor_.YAxisFactor() * delta_size_.Height()) / 2;
    }
  }
  if (shift_side_ & Side::kDown) {
    y += (shift_factor_.YAxisFactor() * delta_size_.Height());
    if (is_center_) {
      y -= (stretch_factor_.YAxisFactor() * delta_size_.Height()) / 2;
    }
  }

  SetModifiedPosition(x, y, position.width(), position.height());
}

void GeometryComposer::ComputeStretching(const QRect& position) {
  int x = position.x();
  int y = position.y();
  int width = position.width();
  int height = position.height();

  if (stretch_side_ & Side::kLeft) {
    width += (stretch_factor_.XAxisFactor() * delta_size_.Width());
    x -= (stretch_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (stretch_side_ & Side::kRight) {
    width += (stretch_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (stretch_side_ & Side::kDown) {
    height += (stretch_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (stretch_side_ & Side::kUp) {
    height += (stretch_factor_.YAxisFactor() * delta_size_.Height());
    y -= (stretch_factor_.YAxisFactor() * delta_size_.Height());
  }

  SetModifiedPosition(x, y, width, height);
}

void GeometryComposer::SetModifiedPosition(int x,
                                           int y,
                                           int width,
                                           int height) {
  modified_position_.setX(x);
  modified_position_.setY(y);
  modified_position_.setWidth(width);
  modified_position_.setHeight(height);
}
