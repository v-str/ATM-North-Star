#include <graphical_login_menu.h>

#include <QWidget>

#include <atm_button.h>
#include <atm_composer.h>
#include <login_menu_geometry.h>
#include <side.h>

GraphicalLoginMenu::GraphicalLoginMenu(QWidget* parent) : BaseAtmFrame(parent) {
  SetInitialFrameGeometry(LoginMenuGeometry::LoginFrame());
  // SetBackButton(LoginMenuGeometry::BackButton());
  SetFrameAnimation(Side::kLeft, Side::kRight, this);

  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}

GraphicalLoginMenu::~GraphicalLoginMenu() {}

void GraphicalLoginMenu::ChangeGeometry(const DeltaSize& delta_size) {
  SetDeltaSize(delta_size);

  AtmComposer::ComposeBackButton(GetBackButton());

  composer_.SetDeltaSize(delta_size);
  composer_.ComposeGeometry(LoginMenuGeometry::LoginFrame(), this);
}
