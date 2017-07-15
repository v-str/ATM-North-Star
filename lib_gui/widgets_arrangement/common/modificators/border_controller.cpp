#include <border_controller.h>

#include <QRect>
#include <QWidget>

void BorderController::SetParentSize(const QRect& parent_size) {
  parent_size_ = parent_size;
}

void BorderController::ControlModifiableWidget(QWidget* widget) {
  modifiable_widget_position_ = widget->geometry();

  ControlUp();
  ControlDown();
  ControlLeft();
  ControlRight();

  widget->setGeometry(modifiable_widget_position_);
}

void BorderController::ControlUp() {}

void BorderController::ControlDown() {}

void BorderController::ControlLeft() {}

void BorderController::ControlRight() {}
