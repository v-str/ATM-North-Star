#include <base_atm_frame.h>

#include <QEasingCurve>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <atm_frame_setter.h>
#include <side.h>
#include <widget_font.h>

BaseAtmFrame::BaseAtmFrame(QWidget* parent,
                           BackButtonCondition back_button_condition)
    : QFrame(parent), frame_setter_(new AtmFrameSetter(this)) {
  switch (back_button_condition) {
    case kBackButtonActivated:
      is_back_button_activated_ = true;
      SetBackButton();
      ColorizeBackButton();
      SetBasicConnections();
      break;
    case kBackButtonDeactivated:
      SetBasicConnections();
      break;
  }
}

BaseAtmFrame::~BaseAtmFrame() {}

void BaseAtmFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void BaseAtmFrame::SetInitialFrameGeometry(const QRect& geometry) {
  setGeometry(geometry);
  initial_frame_geometry_ = geometry;
}

void BaseAtmFrame::SetFrameAnimation(unsigned int hide_to,
                                     unsigned int extrude_from,
                                     QFrame* animated_frame,
                                     unsigned int duration_msec) {
  // SetOperationFrame - always at the first position
  frame_setter_->SetOperationFrame(animated_frame);

  frame_setter_->SetAnimationDirection(hide_to, extrude_from);
  frame_setter_->SetAnimationDuration(duration_msec);
}

void BaseAtmFrame::ColorizeButtons(QList<QPushButton*>* button_list) {
  frame_setter_->ColorizeButtons(button_list);
}

QRect BaseAtmFrame::GetBackButtonGeometry() const {
  return back_button_->geometry();
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

void BaseAtmFrame::Close() { emit PassGeometryForHide(geometry()); }

void BaseAtmFrame::PerformClosing() {
  emit FrameClosed();
  close();
}

void BaseAtmFrame::PerformOpening() {
  emit FrameOpened();
  show();
}

void BaseAtmFrame::ColorizeBackButton() {
  QList<QPushButton*> button_list{back_button_};
  frame_setter_->ColorizeButtons(&button_list);
}

void BaseAtmFrame::SetBasicConnections() {
  if (back_button_ != nullptr) {
    connect(back_button_, SIGNAL(clicked(bool)),
            SLOT(ProcessBackButtonClick()));
  }

  connect(this, SIGNAL(PassGeometryForExtrude(QRect)), frame_setter_,
          SLOT(StartExtrudingFrame(QRect)));
  connect(frame_setter_, SIGNAL(ExtrudingComplete()), SLOT(PerformOpening()));

  connect(this, SIGNAL(PassGeometryForHide(QRect)), frame_setter_,
          SLOT(StartHideFrame(QRect)));
  connect(frame_setter_, SIGNAL(HidingComplete()), SLOT(PerformClosing()));
}

void BaseAtmFrame::SetBackButton() {
  back_button_ = (new AtmButton("Back", this));
  back_button_->SetFontSize(12);
}
