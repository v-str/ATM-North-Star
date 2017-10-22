#include <back_button_composer.h>

#include <atm_button.h>
#include <back_button_property.h>
#include <side.h>

GeometryComposer BackButtonComposer::kBackButtonComposer;

void BackButtonComposer::ComposeBackButton(const DeltaSize& delta_size,
                                           AtmButton* back_button) {
  SetBackButtonSettings();
  kBackButtonComposer.SetDeltaSize(delta_size);
  kBackButtonComposer.ComposeGeometry(BackButtonProperty::BackButtonGeometry(),
                                      back_button);
}

void BackButtonComposer::SetBackButtonSettings() {
  kBackButtonComposer.SetShiftFactor(BackButtonProperty::XShift(),
                                     BackButtonProperty::YShift());
  kBackButtonComposer.SetShiftSide(Side::kRight | Side::kDown);
  kBackButtonComposer.SetStretchFactor(BackButtonProperty::XStretch(),
                                       BackButtonProperty::YStretch());
  kBackButtonComposer.SetStretchSide(Side::kUp | Side::kRight);
  kBackButtonComposer.SetTransformationType(GeometryComposer::kScale);
}
