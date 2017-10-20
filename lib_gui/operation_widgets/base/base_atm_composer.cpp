#include <base_atm_composer.h>

#include <side.h>

BaseAtmComposer::BaseAtmComposer() {
  SetButtonComposer();
  SetFrameComposer();
}

void BaseAtmComposer::SetDeltaSize(const DeltaSize& delta_size) {
  button_composer_.SetDeltaSize(delta_size);
  frame_composer_.SetDeltaSize(delta_size);
}

void BaseAtmComposer::ComposeFrame(QWidget* widget) {
  // perform composing
}

void BaseAtmComposer::ComposeBackButton(const QRect& button_geometry,
                                        QWidget* widget) {
  button_composer_.SetShiftFactor(kButtonShiftX, kButtonShiftY);
  button_composer_.ComposeGeometry(button_geometry, widget);
}

void BaseAtmComposer::SetButtonComposer() {
  button_composer_.SetShiftSide(Side::kRight | Side::kDown);
  button_composer_.SetStretchFactor(kButtonStretchX, kButtonStretchY);
  button_composer_.SetStretchSide(Side::kUp | Side::kRight);
  button_composer_.SetTransformationType(GeometryComposer::kScale);
}

void BaseAtmComposer::SetFrameComposer() {
  frame_composer_.SetStretchFactor(kFrameStretchX, kFrameStretchY);
  frame_composer_.SetStretchSide(Side::kRight | Side::kDown);
}
