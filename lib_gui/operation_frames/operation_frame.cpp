#include <operation_frame.h>

#include <frame_animator.h>

OperationFrame::OperationFrame(QWidget* widget)
    : hide_animator_(new FrameAnimator(widget)),
      extrude_animator_(
          new FrameAnimator(widget, FrameAnimator::kExtrudeFrame)) {}

OperationFrame::~OperationFrame() {
  delete hide_animator_;
  delete extrude_animator_;
}

void OperationFrame::SetAnimationDirection(unsigned int hide_to,
                                           unsigned int extrude_from) {
  hide_animator_->SetAnimationDirection(hide_to);
  extrude_animator_->SetAnimationDirection(extrude_from);
}

void OperationFrame::StartHidingFrame(const QRect& geometry) {
  emit PassParametersForHide(geometry);
}

void OperationFrame::StartExtrudingFrame(const QRect& geometry) {
  emit PassParametersForExtrude(geometry);
}

void OperationFrame::FinishHiding() { emit HidingComplete(); }

void OperationFrame::FinishExtruding() { emit ExtrudingComplete(); }

void OperationFrame::SetConnections() {
  connect(this, SIGNAL(PassParametersForHide(QRect)), hide_animator_,
          SLOT(StartHidingFrame(QRect)));
  connect(hide_animator_, SIGNAL(AnimationComplete()), SLOT(FinishHiding()));
  connect(this, SIGNAL(PassParametersForExtrude(QRect)), extrude_animator_,
          SLOT(ExtrudeFrame(QRect)));
  connect(extrude_animator_, SIGNAL(AnimationComplete()), this,
          SLOT(FinishExtruding()));
}
