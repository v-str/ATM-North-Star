#include <widget_extruder.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QTimer>
#include <QWidget>

#include <side.h>

WidgetExtruder::~WidgetExtruder() { delete extrude_animation_; }

void WidgetExtruder::SetWidgetForExtrudeAnimaiton(QWidget* widget) {
  if (extrude_animation_ != nullptr) {
    delete extrude_animation_;
  }

  extrude_animation_ = new QPropertyAnimation(widget, "geometry");
  extrude_animation_->setDuration(animation_duration_msec_);
  extrude_animation_->setEasingCurve(QEasingCurve::OutCirc);
}

void WidgetExtruder::SetExtrudeDirection(unsigned int direction) {
  extrude_direction_ = direction;
}

void WidgetExtruder::SetAnimationDuration(
    unsigned int animation_duration_msec) {
  animation_duration_msec_ = animation_duration_msec;
  extrude_animation_->setDuration(animation_duration_msec_);
}

void WidgetExtruder::Extrude(const QRect& geometry) {
  SetStartExtrudeAnimation(geometry);
  SetEndExtrudeAnimation(geometry);
  QTimer::singleShot(animation_duration_msec_, this, SLOT(StartAnimation()));
  QTimer::singleShot(animation_duration_msec_, this, SLOT(EndAnimation()));
}

void WidgetExtruder::StartAnimation() { extrude_animation_->start(); }

void WidgetExtruder::EndAnimation() { emit AlreadyExtruded(); }

void WidgetExtruder::SetStartExtrudeAnimation(const QRect& start_geometry) {
  int x = start_geometry.x();
  int y = start_geometry.y();
  int width = start_geometry.width();
  int height = start_geometry.height();

  if (extrude_direction_ & Side::kDown) {
    height = 0;
  }
  if (extrude_direction_ & Side::kUp) {
    y += start_geometry.height();
    height = 0;
  }
  if (extrude_direction_ & Side::kLeft) {
    x += start_geometry.width();
    width = 0;
  }
  if (extrude_direction_ & Side::kRight) {
    width = 0;
  }

  extrude_animation_->setStartValue(QRect(x, y, width, height));
}

void WidgetExtruder::SetEndExtrudeAnimation(const QRect& end_geometry) {
  int x = end_geometry.x();
  int y = end_geometry.y();
  int width = end_geometry.width();
  int height = end_geometry.height();

  extrude_animation_->setEndValue(QRect(x, y, width, height));
}
