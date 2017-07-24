#include <demo_menu.h>

#include <QList>
#include <QResizeEvent>
#include <QTimer>
#include <QWidget>

#include <atm_button.h>
#include <atm_color_designer.h>
#include <demo_menu_geometry.h>
#include <side.h>

DemoMenu::DemoMenu(QWidget* parent)
    : QFrame(parent),
      color_designer_(new AtmColorDesigner),
      back_button_(new AtmButton("back", this)) {
  SetFrameAnimation();
  SetInitialGeometry();
  PaintWidgets();
  SetConnections();
}

DemoMenu::~DemoMenu() { delete color_designer_; }

void DemoMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void DemoMenu::ProcessBackButtonClick() {
  emit PassGeometry(geometry());
  emit BackButtonClicked();
}

void DemoMenu::Show() {
  QRect geometry = {
      DemoMenuGeometry::DemoFrame().x(), DemoMenuGeometry::DemoFrame().y(),
      DemoMenuGeometry::DemoFrame().width() + delta_size_.Width(),
      DemoMenuGeometry::DemoFrame().height() + delta_size_.Height()};

  setGeometry(geometry);
  QTimer::singleShot(widget_hider_.AnimationDurationMSec(), this, SLOT(show()));
}

void DemoMenu::resizeEvent(QResizeEvent*) {
  SetScalingProperties();
  composer_.SetDeltaSize(delta_size_);
  border_controller_.SetGeometryLimit(geometry());
  composer_.ComposeGeometry(DemoMenuGeometry::BackButton(), back_button_);
  border_controller_.ControlWidget(back_button_);
}

void DemoMenu::SetInitialGeometry() {
  setGeometry(DemoMenuGeometry::DemoFrame());
  back_button_->setGeometry(DemoMenuGeometry::BackButton());
}

void DemoMenu::PaintWidgets() {
  color_designer_->PaintFrame(this);
  color_designer_->PaintWidgetSet(QList<QPushButton*>{back_button_});
}

void DemoMenu::SetScalingProperties() {
  composer_.SetShiftFactor(0.0, 1.0);
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetStretchFactor(0.07, 0.03);
  composer_.SetStretchSide(Side::kUp | Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kScale);
}

void DemoMenu::SetFrameAnimation() {
  widget_hider_.SetWidgetForHideAnimation(this);
  widget_hider_.SetHideDirection(Side::kUp | Side::kRight);
}

void DemoMenu::SetConnections() {
  connect(back_button_, SIGNAL(clicked(bool)), SLOT(ProcessBackButtonClick()));
  connect(this, SIGNAL(PassGeometry(QRect)), &widget_hider_, SLOT(Hide(QRect)));
  connect(&widget_hider_, SIGNAL(IsAlreadyHidden()), SLOT(close()));
}
