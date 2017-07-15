#include <border_controller.h>

void BorderController::SetParentSize(const QPoint& parent_size) {
  parent_size_ = parent_size;
}

void BorderController::ControlModifiableWidget(QWidget* widget) {}

void BorderController::ControlUp() {}

void BorderController::ControlDown() {}

void BorderController::ControlLeft() {}

void BorderController::ControlRight() {}
