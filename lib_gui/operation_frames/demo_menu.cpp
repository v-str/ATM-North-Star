#include <demo_menu.h>

#include <QWidget>

#include <atm_color_designer.h>

DemoMenu::DemoMenu(QWidget* parent)
    : QFrame(parent), color_designer_(new AtmColorDesigner) {
  color_designer_->PaintFrame(this);
}

DemoMenu::~DemoMenu() { delete color_designer_; }
