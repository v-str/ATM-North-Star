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

void OperationFrame::HideFrame(const QRect& geometry) {
  emit PassParametersForHide(geometry);
}

void OperationFrame::ExtrudeFrame(const QRect& geometry) {
  emit PassParametersForExtrude(geometry);
}
