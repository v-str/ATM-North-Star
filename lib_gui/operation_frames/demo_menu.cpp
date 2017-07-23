#include <demo_menu.h>

#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <atm_color_designer.h>
#include <demo_menu_geometry.h>

DemoMenu::DemoMenu(QWidget* parent)
    : QFrame(parent),
      color_designer_(new AtmColorDesigner),
      back_button_(new AtmButton("<-", this)) {
  SetInitialGeometry();
  PaintWidgets();
}

DemoMenu::~DemoMenu() { delete color_designer_; }

void DemoMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void DemoMenu::resizeEvent(QResizeEvent*) {}

void DemoMenu::SetInitialGeometry() {
  setGeometry(DemoMenuGeometry::DemoFrame());
  back_button_->setGeometry(DemoMenuGeometry::BackButton());
}

void DemoMenu::PaintWidgets() {
  color_designer_->PaintFrame(this);
  color_designer_->PaintWidgetSet(QList<QPushButton*>{back_button_});
}

void DemoMenu::SetScalingProperties() {}
