#include <widget_extruder.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QRect>
#include <QWidget>

#include <side.h>

WidgetExtruder::~WidgetExtruder() { delete extrude_animation_; }

void WidgetExtruder::SetWidgetForExtrudeAnimaiton(QWidget* widget) {
  if (extrude_animation_ != nullptr) {
    delete extrude_animation_;
  }

  extrude_animation_ = new QPropertyAnimation(widget, "geometry");
  extrude_animation_->setDuration(extrude_animation_msec_);
  extrude_animation_->setEasingCurve(QEasingCurve::OutCirc);
}

void WidgetExtruder::SetExtrudeDirection(unsigned int direction) {
  extrude_direction_ = direction;
}
