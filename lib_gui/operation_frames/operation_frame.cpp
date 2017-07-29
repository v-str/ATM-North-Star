#include <operation_frame.h>

#include <QWidget>

#include <atm_color_designer.h>
#include <frame_animator.h>

OperationFrame::OperationFrame(QWidget* widget)
    : QObject(widget), color_designer_(new AtmColorDesigner) {}

OperationFrame::~OperationFrame() {
  delete color_designer_;
  delete hide_animator_;
  delete extrude_animator_;
}

void OperationFrame::SetOperationFrame(QWidget* widget) {
  InitializeAnimationObjects(widget);

  SetAnimationConnections();
}

void OperationFrame::SetAnimationDirection(unsigned int hide_to,
                                           unsigned int extrude_from) {
  hide_animator_->SetAnimationDirection(hide_to);
  extrude_animator_->SetAnimationDirection(extrude_from);
}

void OperationFrame::SetAnimationDuration(unsigned int duration_msec) {
  hide_animator_->SetDuration(duration_msec);
  extrude_animator_->SetDuration(duration_msec);
}

void OperationFrame::StartHidingFrame(const QRect& geometry) {
  emit PassParametersForHide(geometry);
}

void OperationFrame::StartExtrudingFrame(const QRect& geometry) {
  emit PassParametersForExtrude(geometry);
}

void OperationFrame::FinishHiding() { emit HidingComplete(); }

void OperationFrame::FinishExtruding() { emit ExtrudingComplete(); }

void OperationFrame::InitializeAnimationObjects(QWidget* widget) {
  if (hide_animator_ != nullptr) {
    delete hide_animator_;
  }
  if (extrude_animator_ != nullptr) {
    delete extrude_animator_;
  }

  hide_animator_ = new FrameAnimator(widget);
  extrude_animator_ = new FrameAnimator(widget, FrameAnimator::kExtrudeFrame);
}

void OperationFrame::SetAnimationConnections() {
  connect(this, SIGNAL(PassParametersForExtrude(QRect)), extrude_animator_,
          SLOT(ExtrudeFrame(QRect)));
  connect(extrude_animator_, SIGNAL(AnimationComplete()), this,
          SLOT(FinishExtruding()));

  connect(this, SIGNAL(PassParametersForHide(QRect)), hide_animator_,
          SLOT(HideFrame(QRect)));
  connect(hide_animator_, SIGNAL(AnimationComplete()), SLOT(FinishHiding()));
}
