#include <back_button_composer.h>

#include <atm_button.h>
#include <back_button_property.h>
#include <side.h>

GeometryComposer BackButtonComposer::kBackButtonComposer;
QRect BackButtonComposer::kCurrentBackButtonGeometry;

void BackButtonComposer::ComposeBackButton(const DeltaSize& delta_size,
                                           AtmButton* back_button) {
  SetBackButtonSettings();
  kBackButtonComposer.SetDeltaSize(delta_size);
  kBackButtonComposer.ComposeGeometry(BackButtonProperty::BackButtonGeometry(),
                                      back_button);
  kCurrentBackButtonGeometry = back_button->geometry();
}

DeltaSize BackButtonComposer::GetBackButtonDeltaSize() {
  DeltaSize back_button_delta_size;
  back_button_delta_size.SetWidth(
      kCurrentBackButtonGeometry.width() -
      BackButtonProperty::BackButtonGeometry().width());
  back_button_delta_size.SetHeight(
      kCurrentBackButtonGeometry.height() -
      BackButtonProperty::BackButtonGeometry().height());
  return back_button_delta_size;
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
