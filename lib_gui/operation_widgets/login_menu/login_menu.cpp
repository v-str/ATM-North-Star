#include <login_menu.h>

#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <login_menu_geometry.h>
#include <side.h>

LoginMenu::LoginMenu(QWidget* parent) : BaseAtmFrame(parent) {
  SetInitialFrameGeometry(LoginMenuGeometry::LoginFrame());
  SetInitialBackButtonGeometry(LoginMenuGeometry::BackButton());
  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);
}

LoginMenu::~LoginMenu() {}

void LoginMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}

void LoginMenu::resizeEvent(QResizeEvent*) {
  BaseAtmFrame::SetDeltaSize(delta_size_);
  ScaleBackButton();
}
