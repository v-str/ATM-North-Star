#include <demo_menu.h>

#include <QWidget>

#include <atm_color_designer.h>
#include <demo_menu_geometry.h>

DemoMenu::DemoMenu(QWidget* parent)
    : QFrame(parent), color_designer_(new AtmColorDesigner) {
  color_designer_->PaintFrame(this);
  setGeometry(DemoMenuGeometry::DemoFrame());
}

DemoMenu::~DemoMenu() { delete color_designer_; }
