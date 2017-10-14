#include <registration_menu_geometry.h>

QRect RegistrationMenuGeometry::kRegistrationFrame = {5, 30, 580, 355};
QRect RegistrationMenuGeometry::kDescriptionMenu = {5, 5, 570, 310};
QRect RegistrationMenuGeometry::kBackButton = {5, 320, 50, 30};

QRect RegistrationMenuGeometry::RegistrationFrame() {
  return kRegistrationFrame;
}

QRect RegistrationMenuGeometry::DescriptionMenu() { return kDescriptionMenu; }

QRect RegistrationMenuGeometry::BackButton() { return kBackButton; }
