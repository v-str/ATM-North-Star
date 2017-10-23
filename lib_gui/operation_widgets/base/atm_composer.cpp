#include <atm_composer.h>

#include <atm_button.h>

BackButtonComposer AtmComposer::kBackButtonComposer;
GeometryComposer AtmComposer::kShiftComposer;
GeometryComposer AtmComposer::kStretchComposer;
GeometryComposer AtmComposer::kScaleComposer;
DeltaSize AtmComposer::kDeltaSize;

void AtmComposer::SetDeltaSize(const DeltaSize& delta_size) {
  kDeltaSize = delta_size;
}

void AtmComposer::ComposeBackButton(AtmButton* back_button) {
  kBackButtonComposer.ComposeBackButton(kDeltaSize, back_button);
}

void AtmComposer::ShiftWidget(const QRect& initial_geometry,
                              unsigned int shift_side,
                              double x_shift_factor,
                              double y_shift_factor,
                              QWidget* widget) {
  kShiftComposer.SetDeltaSize(kDeltaSize);
  kShiftComposer.SetShiftSide(shift_side);
  kShiftComposer.SetShiftFactor(x_shift_factor, y_shift_factor);
  kShiftComposer.SetTransformationType(GeometryComposer::kShift);
  kShiftComposer.ComposeGeometry(initial_geometry, widget);
}

void AtmComposer::StretchWidget(const QRect& initial_geometry,
                                unsigned int stretch_side,
                                double x_stretch_factor,
                                double y_stretch_factor,
                                QWidget* widget) {
  kStretchComposer.SetDeltaSize(kDeltaSize);
  kStretchComposer.SetStretchSide(stretch_side);
  kStretchComposer.SetStretchFactor(x_stretch_factor, y_stretch_factor);
  kStretchComposer.SetTransformationType(GeometryComposer::kStretch);
  kStretchComposer.ComposeGeometry(initial_geometry, widget);
}

void AtmComposer::SetScaleWidgetSide(unsigned int shift_side,
                                     unsigned int stretch_side) {
  kScaleComposer.SetShiftSide(shift_side);
  kScaleComposer.SetStretchSide(stretch_side);
}

void AtmComposer::ScaleWidget(const QRect& initial_geometry,
                              double x_shift_factor,
                              double y_shift_factor,
                              double x_stretch_factor,
                              double y_stretch_factor,
                              QWidget* widget) {
  kScaleComposer.SetDeltaSize(kDeltaSize);
  kScaleComposer.SetShiftFactor(x_shift_factor, y_shift_factor);
  kScaleComposer.SetStretchFactor(x_stretch_factor, y_stretch_factor);
  kScaleComposer.SetTransformationType(GeometryComposer::kScale);
  kScaleComposer.ComposeGeometry(initial_geometry, widget);
}

DeltaSize AtmComposer::GetDeltaSize() { return kDeltaSize; }
