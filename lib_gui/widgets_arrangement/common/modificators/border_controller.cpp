#include <border_controller.h>

#include <QRect>
#include <QWidget>

void BorderController::SetParentGeometry(const QRect& parent_size) {
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

void BorderController::SetBorderSpacing(int border_spacer) {
  border_spacer_ = border_spacer;
}

void BorderController::ControlUp() {
  int up_limit =
      parent_size_.y() + modifiable_widget_position_.height() + border_spacer_;

  if (modifiable_widget_position_.y() < up_limit) {
    modifiable_widget_position_.setY(up_limit);
  }
}

void BorderController::ControlDown() {
  int down_limit = parent_size_.height() -
                   modifiable_widget_position_.height() - border_spacer_;

  if (modifiable_widget_position_.y() > down_limit) {
    modifiable_widget_position_.setY(down_limit);
  }
}

void BorderController::ControlLeft() {
  int left_limit =
      parent_size_.x() + modifiable_widget_position_.width() + border_spacer_;

  if (modifiable_widget_position_.x() < left_limit) {
    modifiable_widget_position_.setX(left_limit);
  }
}

void BorderController::ControlRight() {
  int right_limit = parent_size_.width() - modifiable_widget_position_.width() -
                    border_spacer_;

  if (modifiable_widget_position_.x() > right_limit) {
    modifiable_widget_position_ =
        QRect(right_limit, modifiable_widget_position_.y(),
              modifiable_widget_position_.width(),
              modifiable_widget_position_.height());
  }
}
