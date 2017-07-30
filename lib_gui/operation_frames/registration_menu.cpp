#include <registration_menu.h>

#include <QEasingCurve>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <operation_frame.h>
#include <registration_menu_geometry.h>
#include <side.h>

RegistrationMenu::RegistrationMenu(QWidget* parent)
    : QFrame(parent),
      back_button_(new AtmButton("back", this)),
      operation_frame_(new OperationFrame(this)) {
  SetInitialGeometry();
  PaintWidgets();
  SetFrameAnimation();
  SetBackButtonScaling();
  SetConnections();
}

RegistrationMenu::~RegistrationMenu() {
  delete back_button_;
  delete operation_frame_;
}

void RegistrationMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void RegistrationMenu::ProcessBackButtonClick() {
  emit PassGeometryForHide(geometry());
  emit BackButtonClicked();
}

void RegistrationMenu::Show() {
  QRect widget_geometry = {
      RegistrationMenuGeometry::RegistrationFrame().x(),
      RegistrationMenuGeometry::RegistrationFrame().y(),
      RegistrationMenuGeometry::RegistrationFrame().width() +
          delta_size_.Width(),
      RegistrationMenuGeometry::RegistrationFrame().height() +
          delta_size_.Height()};

  setGeometry(widget_geometry);
  emit PassGeometryForExtrude(widget_geometry);
}

void RegistrationMenu::resizeEvent(QResizeEvent*) {
  composer_.SetDeltaSize(delta_size_);
  composer_.SetShiftFactor(0.0, 1.0);
  composer_.ComposeGeometry(RegistrationMenuGeometry::BackButton(),
                            back_button_);

  border_controller_.SetGeometryLimit(geometry());
  border_controller_.ControlWidget(back_button_);
}

void RegistrationMenu::SetInitialGeometry() {
  setGeometry(RegistrationMenuGeometry::RegistrationFrame());
  back_button_->setGeometry(RegistrationMenuGeometry::BackButton());
}

void RegistrationMenu::PaintWidgets() {
  QList<QPushButton*> button_list{back_button_};
  operation_frame_->ColorizeButtons(button_list);
}

void RegistrationMenu::SetFrameAnimation() {
  operation_frame_->SetOperationFrame(this);
  operation_frame_->SetAnimationDirection(Side::kLeft, Side::kRight);
}

void RegistrationMenu::SetConnections() {
  connect(back_button_, SIGNAL(clicked(bool)), SLOT(ProcessBackButtonClick()));
  connect(this, SIGNAL(PassGeometryForExtrude(QRect)), operation_frame_,
          SLOT(StartExtrudingFrame(QRect)));
  connect(operation_frame_, SIGNAL(ExtrudingComplete()), SLOT(show()));
  connect(this, SIGNAL(PassGeometryForHide(QRect)), operation_frame_,
          SLOT(StartHidingFrame(QRect)));
  connect(operation_frame_, SIGNAL(HidingComplete()), SLOT(close()));
}

void RegistrationMenu::SetBackButtonScaling() {
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetStretchFactor(0.07, 0.03);
  composer_.SetStretchSide(Side::kUp | Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kScale);
}
