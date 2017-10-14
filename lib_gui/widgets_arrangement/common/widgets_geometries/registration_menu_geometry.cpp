#include <registration_menu_geometry.h>

QRect RegistrationMenuGeometry::kRegistrationFrame = {5, 30, 580, 355};
QRect RegistrationMenuGeometry::kDescriptionMenu = {45, 30, 395, 225};
QRect RegistrationMenuGeometry::kBackButton = {5, 320, 50, 30};

QRect RegistrationMenuGeometry::RegistrationFrame() {
  return kRegistrationFrame;
}

QRect RegistrationMenuGeometry::DescriptionMenu() { return kDescriptionMenu; }

QRect RegistrationMenuGeometry::BackButton() { return kBackButton; }
