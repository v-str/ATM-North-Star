#include <graphical_login_menu.h>

#include <QWidget>

#include <atm_button.h>
#include <atm_composer.h>
#include <login_menu_geometry.h>

GraphicalLoginMenu::GraphicalLoginMenu(QWidget* parent) : BaseAtmFrame(parent) {
  SetInitialFrameGeometry(LoginMenuGeometry::LoginFrame());
  SetFrameAnimation(Side::kLeft, Side::kRight, this);
}

GraphicalLoginMenu::~GraphicalLoginMenu() {}

void GraphicalLoginMenu::ChangeGeometry() {
  SetDeltaSize(AtmComposer::GetDeltaSize());

  AtmComposer::ComposeBackButton(BackButton());
  AtmComposer::StretchWidget(LoginMenuGeometry::LoginFrame(),
                             Side::kRight | Side::kDown, 1.0, 1.0, this);
}
