#include <geometry_composer.h>

#include <QWidget>

#include <side.h>

void GeometryComposer::SetDeltaSize(const DeltaSize& delta_size) {
  shifter_.SetDeltaSize(delta_size);
  stretcher_.SetDeltaSize(delta_size);
}

void GeometryComposer::SetParentGeometry(const QRect& parent_geometry) {
  parent_geometry_ = parent_geometry;
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
      ComputeShifting(modified_widget_geometry_);
      break;
  }
  widget->setGeometry(modified_widget_geometry_);
}

void GeometryComposer::SetShiftFactor(double x_shift_factor,
                                      double y_shift_factor) {
  shifter_.SetShiftFactor(ConversionFactor(x_shift_factor, y_shift_factor));
}

void GeometryComposer::SetStretchFactor(double x_stretch_factor,
                                        double y_stretch_factor) {
  shifter_.SetStretchFactor(
      ConversionFactor(x_stretch_factor, y_stretch_factor));
  stretcher_.SetStretchFactor(
      ConversionFactor(x_stretch_factor, y_stretch_factor));
}

void GeometryComposer::SetShiftSide(unsigned int shift_side) {
  shifter_.SetshiftSide(shift_side);
}

void GeometryComposer::SetStretchSide(unsigned int stretch_side) {
  stretcher_.SetStretchSide(stretch_side);
}

void GeometryComposer::SetTransformationType(
    GeometryComposer::TransformationType type) {
  type_ = type;
}

void GeometryComposer::KeepCenter(bool is_center) {
  shifter_.SetCenter(is_center);
}

void GeometryComposer::ComputeShifting(const QRect& position) {
  shifter_.ComputeShifting(position);

  SetModifiedPosition(shifter_.XPos(), shifter_.YPOs(), position.width(),
                      position.height());
}

void GeometryComposer::ComputeStretching(const QRect& position) {
  stretcher_.ComputeStretching(position);

  SetModifiedPosition(stretcher_.XPos(), stretcher_.YPos(), stretcher_.Width(),
                      stretcher_.Height());
}

void GeometryComposer::SetModifiedPosition(int x,
                                           int y,
                                           int width,
                                           int height) {
  modified_widget_geometry_.setX(x);
  modified_widget_geometry_.setY(y);
  modified_widget_geometry_.setWidth(width);
  modified_widget_geometry_.setHeight(height);
}
