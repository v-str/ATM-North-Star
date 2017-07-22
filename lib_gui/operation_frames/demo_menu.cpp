#include <demo_menu.h>

#include <QResizeEvent>
#include <QWidget>

#include <atm_color_designer.h>
#include <demo_menu_geometry.h>

DemoMenu::DemoMenu(QWidget* parent)
    : QFrame(parent), color_designer_(new AtmColorDesigner) {
  setGeometry(DemoMenuGeometry::DemoFrame());
  color_designer_->PaintFrame(this);
}

DemoMenu::~DemoMenu() { delete color_designer_; }

void DemoMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void DemoMenu::resizeEvent(QResizeEvent*) {}

void DemoMenu::SetScalingProperties() {}
