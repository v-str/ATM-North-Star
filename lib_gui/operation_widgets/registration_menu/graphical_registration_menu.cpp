#include <graphical_registration_menu.h>

#include <QWidget>

#include <atm_button.h>
#include <registration_menu_geometry.h>
#include <side.h>

GraphicalRegistrationMenu::GraphicalRegistrationMenu(QWidget* parent)
    : BaseAtmFrame(parent) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::RegistrationFrame());
  SetBackButton(RegistrationMenuGeometry::BackButton());
  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);
  SetDefaultComposerSettings();
}

GraphicalRegistrationMenu::~GraphicalRegistrationMenu() {}

void GraphicalRegistrationMenu::ChangeRegistrationMenuGeometry(
    const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  ScaleBackButton();
  composer_.SetDeltaSize(delta_size);
  composer_.ComposeGeometry(RegistrationMenuGeometry::RegistrationFrame(),
                            this);
}

void GraphicalRegistrationMenu::SetDefaultComposerSettings() {
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}
