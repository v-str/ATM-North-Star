#include <demo_menu.h>

#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <demo_menu_geometry.h>
#include <side.h>

DemoMenu::DemoMenu(QWidget* parent) : BaseAtmFrame(parent) {
  SetInitialFrameGeometry(DemoMenuGeometry::DemoFrame());
  SetInitialBackButtonGeometry(DemoMenuGeometry::BackButton());
  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);
}

DemoMenu::~DemoMenu() {}

void DemoMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}

void DemoMenu::resizeEvent(QResizeEvent*) {
  BaseAtmFrame::SetDeltaSize(delta_size_);
  ScaleBackButton();
}
