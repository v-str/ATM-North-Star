#include <geometry_composer.h>

#include <QRect>
#include <QWidget>

#include <side.h>

void GeometryComposer::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void GeometryComposer::ComposeGeometry(
    const ConversionFactor& conversion_factor,
    const QRect& initial_position,
    TransformationType type,
    unsigned int manipulation_flag,
    QWidget* widget) {
  conversion_factor_ = conversion_factor;
  switch (type) {
    case kShift:
      ComputeShifting(initial_position, manipulation_flag);
      break;
    case kStretch:
      ComputeStretching(initial_position, manipulation_flag);
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

void GeometryComposer::ComputeShifting(const QRect& initial_position,
                                       unsigned int manipulation_flag) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (manipulation_flag & Side::kLeft) {
    x -= (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kRight) {
    x += (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kUp) {
    y -= (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (manipulation_flag & Side::kDown) {
    y += (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }

  SetModifiedPosition(x, y, initial_position.width(),
                      initial_position.height());
}

void GeometryComposer::ComputeStretching(const QRect& initial_position,
                                         unsigned int manipulation_flag) {
  int x = initial_position.x();
  int y = initial_position.y();
  int width = initial_position.width();
  int height = initial_position.height();

  if (manipulation_flag & Side::kLeft) {
    width += (conversion_factor_.XAxisFactor() * delta_size_.Width());
    x -= (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kRight) {
    width += (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kDown) {
    height += (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (manipulation_flag & Side::kUp) {
    height += (conversion_factor_.YAxisFactor() * delta_size_.Height());
    y -= (conversion_factor_.YAxisFactor() * delta_size_.Height());
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
