#include <base_atm_composer.h>

#include <side.h>

BaseAtmComposer::BaseAtmComposer() { SetButtonComposer(); }

void BaseAtmComposer::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void BaseAtmComposer::ComposeFrame(QWidget* widget) {
  // perform composing
}

void BaseAtmComposer::ComposeBackButton(QWidget* widget) {
  // perform composing
}

void BaseAtmComposer::SetButtonComposer() {
  button_composer_.SetShiftSide(Side::kRight | Side::kDown);
  button_composer_.SetStretchFactor(kButtonStretchX, kButtonStretchY);
  button_composer_.SetStretchSide(Side::kUp | Side::kRight);
  button_composer_.SetTransformationType(GeometryComposer::kScale);
}
