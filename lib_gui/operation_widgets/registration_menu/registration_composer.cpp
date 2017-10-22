#include <registration_composer.h>

#include <QWidget>

#include <registration_description.h>
#include <registration_menu_geometry.h>
#include <side.h>

RegistrationComposer::RegistrationComposer() { SetDefaultComposingSettings(); }

void RegistrationComposer::ComposeRegistrationMenu(const DeltaSize& delta_size,
                                                   QWidget* registation_menu) {
  composer_.SetDeltaSize(delta_size);
  composer_.ComposeGeometry(RegistrationMenuGeometry::RegistrationFrame(),
                            registation_menu);
}

DeltaSize RegistrationComposer::ComposeDeltaSizeForDescription(
    const QRect& back_button_geometry,
    const DeltaSize& basic_delta_size) const {
  int back_button_delta_height =
      back_button_geometry.height() -
      RegistrationMenuGeometry::BackButton().height();

  int delta_height = basic_delta_size.Height() - back_button_delta_height;

  return DeltaSize(basic_delta_size.Width(), delta_height);
}

void RegistrationComposer::SetDefaultComposingSettings() {
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}
