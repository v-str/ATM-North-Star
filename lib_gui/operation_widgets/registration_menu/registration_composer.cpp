#include <registration_composer.h>

#include <QWidget>

#include <registration_menu_geometry.h>
#include <side.h>

RegistrationComposer::RegistrationComposer() { SetDefaultComposingSettings(); }

void RegistrationComposer::ComposeGeometry(const DeltaSize& delta_size,
                                           QWidget* widget_for_compose) {
  composer_.SetDeltaSize(delta_size);
  composer_.ComposeGeometry(RegistrationMenuGeometry::RegistrationFrame(),
                            widget_for_compose);
}

void RegistrationComposer::SetDefaultComposingSettings() {
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}
