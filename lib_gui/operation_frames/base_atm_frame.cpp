#include <base_atm_frame.h>

#include <QEasingCurve>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <operation_frame.h>
#include <registration_menu_geometry.h>
#include <side.h>

BaseAtmFrame::BaseAtmFrame(QWidget* parent)
    : QFrame(parent),
      back_button_(new AtmButton("back", this)),
      operation_frame_(new OperationFrame(this)) {
  ColorizeBackButton();
  SetConnections();
  SetBackButtonScaling();
}

BaseAtmFrame::~BaseAtmFrame() {}

void BaseAtmFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void BaseAtmFrame::SetInitialFrameGeometry(const QRect& geometry) {
  setGeometry(geometry);
  initial_frame_geometry_ = geometry;
}

void BaseAtmFrame::SetBackButtonGeometry(const QRect& geometry) {
  back_button_->setGeometry(geometry);
}

void BaseAtmFrame::SetFrameAnimation(unsigned int hide_to,
                                     unsigned int extrude_from,
                                     unsigned int duration_msec,
                                     QFrame* animated_frame) {
  // SetOperationFrame - always at the first position
  operation_frame_->SetOperationFrame(animated_frame);
  operation_frame_->SetAnimationDirection(hide_to, extrude_from);
  operation_frame_->SetAnimationDuration(duration_msec);
}

void BaseAtmFrame::ProcessBackButtonClick() {
  emit PassGeometryForHide(geometry());
  emit BackButtonClicked();
}

void BaseAtmFrame::Show() {
  QRect widget_geometry = {
      initial_frame_geometry_.x(), initial_frame_geometry_.y(),
      initial_frame_geometry_.width() + delta_size_.Width(),
      initial_frame_geometry_.height() + delta_size_.Height()};

  setGeometry(widget_geometry);
  emit PassGeometryForExtrude(widget_geometry);
}

void BaseAtmFrame::resizeEvent(QResizeEvent*) {
  composer_.SetDeltaSize(delta_size_);
  composer_.SetShiftFactor(0.0, 1.0);
  composer_.ComposeGeometry(RegistrationMenuGeometry::BackButton(),
                            back_button_);

  border_controller_.SetGeometryLimit(geometry());
  border_controller_.ControlWidget(back_button_);
}

void BaseAtmFrame::ColorizeBackButton() {
  QList<QPushButton*> button_list{back_button_};
  operation_frame_->ColorizeButtons(button_list);
}

void BaseAtmFrame::SetConnections() {
  connect(back_button_, SIGNAL(clicked(bool)), SLOT(ProcessBackButtonClick()));
  connect(this, SIGNAL(PassGeometryForExtrude(QRect)), operation_frame_,
          SLOT(StartExtrudingFrame(QRect)));
  connect(operation_frame_, SIGNAL(ExtrudingComplete()), SLOT(show()));
  connect(this, SIGNAL(PassGeometryForHide(QRect)), operation_frame_,
          SLOT(StartHidingFrame(QRect)));
  connect(operation_frame_, SIGNAL(HidingComplete()), SLOT(close()));
}

void BaseAtmFrame::SetBackButtonScaling() {
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetStretchFactor(0.07, 0.03);
  composer_.SetStretchSide(Side::kUp | Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kScale);
}
