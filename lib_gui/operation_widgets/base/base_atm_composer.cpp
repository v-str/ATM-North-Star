#include <base_atm_composer.h>

#include <button_property.h>
#include <frame_property.h>
#include <side.h>

BaseAtmComposer::BaseAtmComposer() {
  SetButtonComposer();
  SetFrameComposer();
}

void BaseAtmComposer::SetDeltaSize(const DeltaSize& delta_size) {
  button_composer_.SetDeltaSize(delta_size);
  frame_composer_.SetDeltaSize(delta_size);
}

void BaseAtmComposer::ComposeFrame(const QRect& frame_geometry,
                                   QWidget* widget) {
  frame_composer_.ComposeGeometry(frame_geometry, widget);
}

void BaseAtmComposer::ComposeBackButton(const QRect& button_geometry,
                                        QWidget* widget) {
  button_composer_.ComposeGeometry(button_geometry, widget);
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

void BaseAtmComposer::SetFrameComposer() {
  frame_composer_.SetStretchFactor(FrameProperty::StretchX(),
                                   FrameProperty::StretchY());
  frame_composer_.SetStretchSide(Side::kRight | Side::kDown);
}
