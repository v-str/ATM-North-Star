#include <operation_frame.h>

#include <frame_animator.h>

OperationFrame::OperationFrame(QWidget* widget)
    : hide_animator_(new FrameAnimator), extrude_animator_(new FrameAnimator) {}

OperationFrame::~OperationFrame() {
  delete hide_animator_;
  delete extrude_animator_;
}
