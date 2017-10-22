#include <base_composer.h>

#include <atm_button.h>
#include <back_button_property.h>
#include <side.h>

void BaseComposer::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void BaseComposer::ComposeBackButton(AtmButton* back_button) {}

void BaseComposer::SetBackButtonSettings() {
  back_button_composer_.SetShiftFactor(BackButtonProperty::XShift(),
                                       BackButtonProperty::YShift());
  back_button_composer_.SetShiftSide(Side::kRight | Side::kDown);
  back_button_composer_.SetStretchFactor(BackButtonProperty::XStretch(),
                                         BackButtonProperty::YStretch());
  back_button_composer_.SetStretchSide(Side::kUp | Side::kRight);
  back_button_composer_.SetTransformationType(GeometryComposer::kScale);
}
