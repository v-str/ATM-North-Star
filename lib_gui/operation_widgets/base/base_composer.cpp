#include <base_composer.h>

#include <atm_button.h>
#include <back_button_property.h>
#include <side.h>

GeometryComposer BaseComposer::kBackButtonCompser;
DeltaSize BaseComposer::kDeltaSize;

BaseComposer::BaseComposer() { SetBackButtonSettings(); }

void BaseComposer::SetDeltaSize(const DeltaSize& delta_size) {
  kDeltaSize = delta_size;
}

void BaseComposer::ComposeBackButton(AtmButton* back_button) {
  kBackButtonCompser.SetDeltaSize(kDeltaSize);
  kBackButtonCompser.ComposeGeometry(BackButtonProperty::BackButtonGeometry(),
                                     back_button);
}

void BaseComposer::SetBackButtonSettings() {
  kBackButtonCompser.SetShiftFactor(BackButtonProperty::XShift(),
                                    BackButtonProperty::YShift());
  kBackButtonCompser.SetShiftSide(Side::kRight | Side::kDown);
  kBackButtonCompser.SetStretchFactor(BackButtonProperty::XStretch(),
                                      BackButtonProperty::YStretch());
  kBackButtonCompser.SetStretchSide(Side::kUp | Side::kRight);
  kBackButtonCompser.SetTransformationType(GeometryComposer::kScale);
}
