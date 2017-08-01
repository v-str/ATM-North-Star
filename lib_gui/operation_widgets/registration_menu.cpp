#include <registration_menu.h>

#include <QEasingCurve>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <registration_menu_geometry.h>
#include <side.h>

RegistrationMenu::RegistrationMenu(QWidget* parent) : BaseAtmFrame(parent) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::RegistrationFrame());
  SetInitialBackButtonGeometry(RegistrationMenuGeometry::BackButton());
  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);
}

RegistrationMenu::~RegistrationMenu() {}

void RegistrationMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}

void RegistrationMenu::resizeEvent(QResizeEvent*) {
  BaseAtmFrame::SetDeltaSize(delta_size_);
  ScaleBackButton();
}
