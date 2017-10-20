#include <base_atm_composer.h>

#include <button_property.h>
#include <frame_property.h>
#include <side.h>

BaseAtmComposer::BaseAtmComposer() {
  SetFrameComposer();
  SetButtonComposer();
}

void BaseAtmComposer::SetDeltaSize(const DeltaSize& delta_size) {
  frame_composer_.SetDeltaSize(delta_size);
  button_composer_.SetDeltaSize(delta_size);
}

void BaseAtmComposer::ComposeFrame(QWidget* widget) {
  frame_composer_.ComposeGeometry(frame_geometry_, widget);
}

void BaseAtmComposer::ComposeBackButton(QWidget* widget) {
  button_composer_.ComposeGeometry(button_geometry_, widget);
}

void BaseAtmComposer::SetFrameGeometry(const QRect& frame_geometry) {
  frame_geometry_ = frame_geometry;
}

void BaseAtmComposer::SetButtonGeometry(const QRect& button_geometry) {
  button_geometry_ = button_geometry;
}

void BaseAtmComposer::SetFrameComposer() {
  frame_composer_.SetStretchFactor(FrameProperty::StretchX(),
                                   FrameProperty::StretchY());
  frame_composer_.SetStretchSide(Side::kRight | Side::kDown);
}

void BaseAtmComposer::SetButtonComposer() {
  button_composer_.SetShiftFactor(ButtonProperty::ShiftX(),
                                  ButtonProperty::ShiftY());
  button_composer_.SetShiftSide(Side::kRight | Side::kDown);

  button_composer_.SetStretchFactor(ButtonProperty::StretchX(),
                                    ButtonProperty::StretchY());
  button_composer_.SetStretchSide(Side::kUp | Side::kRight);

  button_composer_.SetTransformationType(GeometryComposer::kScale);
}
