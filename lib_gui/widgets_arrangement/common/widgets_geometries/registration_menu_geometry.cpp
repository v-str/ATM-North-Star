#include <registration_menu_geometry.h>

QRect RegistrationMenuGeometry::kRegistrationFrame = {5, 30, 580, 355};
QRect RegistrationMenuGeometry::kDescriptionFrame = {5, 5, 570, 310};
QRect RegistrationMenuGeometry::kNextButton = {200, 150, 100, 50};
QRect RegistrationMenuGeometry::kBackButton = {5, 320, 50, 30};

QRect RegistrationMenuGeometry::RegistrationFrame() {
  return kRegistrationFrame;
}

QRect RegistrationMenuGeometry::DescriptionFrame() { return kDescriptionFrame; }

QRect RegistrationMenuGeometry::NextButton() { return kNextButton; }

QRect RegistrationMenuGeometry::BackButton() { return kBackButton; }
