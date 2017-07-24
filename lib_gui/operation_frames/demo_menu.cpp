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
  emit PassGeometryForHide(geometry());
  emit BackButtonClicked();
}

void DemoMenu::Show() {
  QRect widget_geometry = {
      DemoMenuGeometry::DemoFrame().x(), DemoMenuGeometry::DemoFrame().y(),
      DemoMenuGeometry::DemoFrame().width() + delta_size_.Width(),
      DemoMenuGeometry::DemoFrame().height() + delta_size_.Height()};

  setGeometry(widget_geometry);
  emit PassGeometryForExtrude(widget_geometry);
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

  widget_extruder_.SetWidgetForExtrudeAnimaiton(this);
  widget_extruder_.SetExtrudeDirection(Side::kDown | Side::kRight);
}

void DemoMenu::SetConnections() {
  connect(this, SIGNAL(PassGeometryForExtrude(QRect)), &widget_extruder_,
          SLOT(Extrude(QRect)));
  connect(&widget_extruder_, SIGNAL(AlreadyExtruded()), SLOT(show()));

  connect(back_button_, SIGNAL(clicked(bool)), SLOT(ProcessBackButtonClick()));
  connect(this, SIGNAL(PassGeometryForHide(QRect)), &widget_hider_,
          SLOT(Hide(QRect)));
  connect(&widget_hider_, SIGNAL(IsAlreadyHidden()), SLOT(close()));
}
