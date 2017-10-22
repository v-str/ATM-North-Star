#include <atm_composer.h>

#include <atm_button.h>
#include <back_button_property.h>
#include <side.h>

GeometryComposer AtmComposer::kBackButtonComposer;
DeltaSize AtmComposer::kDeltaSize;

AtmComposer::AtmComposer() { SetBackButtonSettings(); }

void AtmComposer::SetDeltaSize(const DeltaSize& delta_size) {
  kDeltaSize = delta_size;
}

void AtmComposer::ComposeBackButton(AtmButton* back_button) {
  kBackButtonComposer.SetDeltaSize(kDeltaSize);
  kBackButtonComposer.ComposeGeometry(BackButtonProperty::BackButtonGeometry(),
                                      back_button);
}

void AtmComposer::SetBackButtonSettings() {
  kBackButtonComposer.SetShiftFactor(BackButtonProperty::XShift(),
                                     BackButtonProperty::YShift());
  kBackButtonComposer.SetShiftSide(Side::kRight | Side::kDown);
  kBackButtonComposer.SetStretchFactor(BackButtonProperty::XStretch(),
                                       BackButtonProperty::YStretch());
  kBackButtonComposer.SetStretchSide(Side::kUp | Side::kRight);
  kBackButtonComposer.SetTransformationType(GeometryComposer::kScale);
}
