#include <widget_extruder.h>

#include <QPropertyAnimation>
#include <QRect>
#include <QWidget>

WidgetExtruder::~WidgetExtruder() {}

void WidgetExtruder::SetWidgetForExtrudeAnimaiton(QWidget* widget) {}

void WidgetExtruder::SetExtrudeDirection(unsigned int direction) {}

bool WidgetExtruder::IsExtruded() const {}

void WidgetExtruder::Extrude(const QRect& geometry) {}

void WidgetExtruder::AnimationTimeOut() {}

void WidgetExtruder::SetStartExtrudeAnimation(const QRect& start_value) {}

void WidgetExtruder::SetEndExtrudeAnimation(const QRect& end_value) {}
