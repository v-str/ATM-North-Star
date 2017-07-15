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
  border_spacing_ = border_spacer;
}

void BorderController::ControlUp() {
  int up_limit = border_spacing_;

  if (modifiable_widget_position_.y() < up_limit) {
    modifiable_widget_position_ =
        QRect(modifiable_widget_position_.x(), up_limit,
              modifiable_widget_position_.width(),
              modifiable_widget_position_.height());
  }
}

void BorderController::ControlDown() {
  int down_limit = parent_size_.height() -
                   modifiable_widget_position_.height() - border_spacing_;

  if (modifiable_widget_position_.y() > down_limit) {
    modifiable_widget_position_ =
        QRect(modifiable_widget_position_.x(), down_limit,
              modifiable_widget_position_.width(),
              modifiable_widget_position_.height());
  }
}

void BorderController::ControlLeft() {
  int left_limit = border_spacing_;

  if (modifiable_widget_position_.x() < left_limit) {
    modifiable_widget_position_ =
        QRect(left_limit, modifiable_widget_position_.y(),
              modifiable_widget_position_.width(),
              modifiable_widget_position_.height());
  }
}

void BorderController::ControlRight() {
  int right_limit = parent_size_.width() - modifiable_widget_position_.width() -
                    border_spacing_;

  if (modifiable_widget_position_.x() > right_limit) {
    modifiable_widget_position_ =
        QRect(right_limit, modifiable_widget_position_.y(),
              modifiable_widget_position_.width(),
              modifiable_widget_position_.height());
  }
}
