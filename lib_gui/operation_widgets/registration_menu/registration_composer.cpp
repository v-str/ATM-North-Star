#include <registration_composer.h>

#include <QWidget>

#include <registration_description.h>
#include <registration_menu_geometry.h>
#include <side.h>

DeltaSize RegistrationComposer::ComposeDeltaSizeForDescription(
    const QRect& back_button_geometry,
    const DeltaSize& basic_delta_size) const {
  int back_button_delta_height =
      back_button_geometry.height() -
      RegistrationMenuGeometry::BackButton().height();

  int delta_height = basic_delta_size.Height() - back_button_delta_height;

  return DeltaSize(basic_delta_size.Width(), delta_height);
}
