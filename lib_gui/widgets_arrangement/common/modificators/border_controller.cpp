#include <border_controller.h>

#include <QRect>
#include <QWidget>

void BorderController::SetParentSize(const QPoint& parent_size) {
  parent_size_ = parent_size;
}

void BorderController::ControlModifiableWidget(QWidget* widget) {
  modifiable_widget_position_ = QPoint(widget->x(), widget->y());

  ControlUp();
  ControlDown();
  ControlLeft();
  ControlRight();

  widget->setGeometry(QRect(modifiable_widget_position_.x(),
                            modifiable_widget_position_.y(), widget->width(),
                            widget->height()));
}

void BorderController::ControlUp() {}

void BorderController::ControlDown() {}

void BorderController::ControlLeft() {}

void BorderController::ControlRight() {}
