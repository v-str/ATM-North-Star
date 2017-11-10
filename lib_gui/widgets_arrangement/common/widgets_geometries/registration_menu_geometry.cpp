#include <registration_menu_geometry.h>

QRect RegistrationMenuGeometry::kRegistrationFrame = {5, 30, 580, 355};
QRect RegistrationMenuGeometry::kDescriptionFrame = {5, 5, 570, 310};
QRect RegistrationMenuGeometry::kDescriptionLabel = {5, 5, 560, 250};
QRect RegistrationMenuGeometry::kBackButton = {5, 320, 50, 30};

QRect RegistrationMenuGeometry::kFamiliarizedCheckbox = {5, 260, 560, 30};

QRect RegistrationMenuGeometry::RegistrationFrame() {
  return kRegistrationFrame;
}

QRect RegistrationMenuGeometry::DescriptionFrame() { return kDescriptionFrame; }

QRect RegistrationMenuGeometry::DesctiptionLabel() { return kDescriptionLabel; }

QRect RegistrationMenuGeometry::BackButton() { return kBackButton; }

QRect RegistrationMenuGeometry::FamiliarizedCheckbox() {
  return kFamiliarizedCheckbox;
}
