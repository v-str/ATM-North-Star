#include <demo_menu.h>

#include <QEasingCurve>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <demo_menu_geometry.h>
#include <operation_frame.h>
#include <side.h>

DemoMenu::DemoMenu(QWidget* parent)
    : QFrame(parent),
      back_button_(new AtmButton("back", this)),
      operation_frame_(new OperationFrame(this)) {
  SetFrameAnimation();
  SetInitialGeometry();
  PaintWidgets();
  SetConnections();
}

DemoMenu::~DemoMenu() {}

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
  QList<QPushButton*> button_list{back_button_};
  operation_frame_->ColorizeButtons(button_list);
}

void DemoMenu::SetScalingProperties() {
  composer_.SetShiftFactor(0.0, 1.0);
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetStretchFactor(0.07, 0.03);
  composer_.SetStretchSide(Side::kUp | Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kScale);
}

void DemoMenu::SetFrameAnimation() {
  operation_frame_->SetOperationFrame(this);
  operation_frame_->SetAnimationDirection(Side::kDown, Side::kUp);
}

void DemoMenu::SetConnections() {
  connect(back_button_, SIGNAL(clicked(bool)), SLOT(ProcessBackButtonClick()));

  connect(this, SIGNAL(PassGeometryForExtrude(QRect)), operation_frame_,
          SLOT(StartExtrudingFrame(QRect)));

  connect(operation_frame_, SIGNAL(ExtrudingComplete()), SLOT(show()));

  connect(this, SIGNAL(PassGeometryForHide(QRect)), operation_frame_,
          SLOT(StartHidingFrame(QRect)));

  connect(operation_frame_, SIGNAL(HidingComplete()), SLOT(close()));
}
