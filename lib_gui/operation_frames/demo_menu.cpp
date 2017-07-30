#include <demo_menu.h>

#include <QEasingCurve>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <demo_menu_geometry.h>
#include <side.h>

DemoMenu::DemoMenu(QWidget* parent) : BaseAtmFrame(parent) {
  SetInitialFrameGeometry(DemoMenuGeometry::DemoFrame());
  SetBackButtonGeometry(DemoMenuGeometry::BackButton());
  SetFrameAnimation(Side::kLeft, Side::kRight, 500, this);
}

DemoMenu::~DemoMenu() {}

void DemoMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}

void DemoMenu::resizeEvent(QResizeEvent*) {}
