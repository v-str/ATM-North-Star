#include <atm_frame_setter.h>

#include <QFrame>
#include <QPushButton>

#include <atm_color_designer.h>
#include <frame_animator.h>

AtmFrameSetter::AtmFrameSetter(QFrame* frame) : QObject(frame) {}

AtmFrameSetter::~AtmFrameSetter() {
  delete hide_animator_;
  delete extrude_animator_;
}

void AtmFrameSetter::SetOperationFrame(QFrame* frame) {
  AtmColorDesigner::PaintFrame(frame);

  InitializeAnimationObjects(frame);

  SetAnimationConnections();
}

void AtmFrameSetter::SetAnimationDirection(unsigned int hide_to,
                                           unsigned int extrude_from) {
  hide_animator_->SetAnimationDirection(hide_to);
  extrude_animator_->SetAnimationDirection(extrude_from);
}

void AtmFrameSetter::SetAnimationDuration(unsigned int duration_msec) {
  hide_animator_->SetDuration(duration_msec);
  extrude_animator_->SetDuration(duration_msec);
}

void AtmFrameSetter::ColorizeButtons(QList<QPushButton*>* button_list) {
  AtmColorDesigner::PaintWidgetSet(button_list);
}

void AtmFrameSetter::StartHideFrame(const QRect& geometry) {
  emit PassGeometryForHide(geometry);
}

void AtmFrameSetter::StartExtrudingFrame(const QRect& geometry) {
  emit PassGeometryForExtrude(geometry);
}

void AtmFrameSetter::FinishHiding() { emit HidingComplete(); }

void AtmFrameSetter::FinishExtruding() { emit ExtrudingComplete(); }

void AtmFrameSetter::InitializeAnimationObjects(QFrame* frame) {
  if (hide_animator_ != nullptr) {
    delete hide_animator_;
  }
  if (extrude_animator_ != nullptr) {
    delete extrude_animator_;
  }

  hide_animator_ = new FrameAnimator(frame);
  extrude_animator_ = new FrameAnimator(frame, FrameAnimator::kExtrudeFrame);
}

void AtmFrameSetter::SetAnimationConnections() {
  connect(this, SIGNAL(PassGeometryForExtrude(QRect)), extrude_animator_,
          SLOT(Extrude(QRect)));
  connect(extrude_animator_, SIGNAL(AnimationComplete()), this,
          SLOT(FinishExtruding()));

  connect(this, SIGNAL(PassGeometryForHide(QRect)), hide_animator_,
          SLOT(Hide(QRect)));
  connect(hide_animator_, SIGNAL(AnimationComplete()), SLOT(FinishHiding()));
}
