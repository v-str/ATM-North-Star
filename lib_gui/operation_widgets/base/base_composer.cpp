#include <base_composer.h>

#include <atm_button.h>
#include <back_button_property.h>
#include <side.h>

GeometryComposer BaseComposer::kBackButtonComposer;
DeltaSize BaseComposer::kDeltaSize;

BaseComposer::BaseComposer() { SetBackButtonSettings(); }

void BaseComposer::SetDeltaSize(const DeltaSize& delta_size) {
  kDeltaSize = delta_size;
}

void BaseComposer::ComposeBackButton(AtmButton* back_button) {
  kBackButtonComposer.SetDeltaSize(kDeltaSize);
  kBackButtonComposer.ComposeGeometry(BackButtonProperty::BackButtonGeometry(),
                                      back_button);
}

void BaseComposer::SetBackButtonSettings() {
  kBackButtonComposer.SetShiftFactor(BackButtonProperty::XShift(),
                                     BackButtonProperty::YShift());
  kBackButtonComposer.SetShiftSide(Side::kRight | Side::kDown);
  kBackButtonComposer.SetStretchFactor(BackButtonProperty::XStretch(),
                                       BackButtonProperty::YStretch());
  kBackButtonComposer.SetStretchSide(Side::kUp | Side::kRight);
  kBackButtonComposer.SetTransformationType(GeometryComposer::kScale);
}
