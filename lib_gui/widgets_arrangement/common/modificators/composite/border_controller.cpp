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

bool BorderController::IsBorderOverstepped() { return is_border_overstepped; }

void BorderController::ControlUp() {
  int up_limit = border_spacing_;

  if (modifiable_widget_position_.y() < up_limit) {
    is_border_overstepped = true;
    SetModifiedHeight(up_limit);
  } else {
    is_border_overstepped = false;
  }
}

void BorderController::ControlDown() {
  int down_limit = parent_size_.height() -
                   modifiable_widget_position_.height() - border_spacing_;

  if (modifiable_widget_position_.y() > down_limit) {
    is_border_overstepped = true;
    SetModifiedHeight(down_limit);
  } else {
    is_border_overstepped = false;
  }
}

void BorderController::ControlLeft() {
  int left_limit = border_spacing_;

  if (modifiable_widget_position_.x() < left_limit) {
    is_border_overstepped = true;
    SetModifiedWidth(left_limit);
  } else {
    is_border_overstepped = false;
  }
}

void BorderController::ControlRight() {
  int right_limit = parent_size_.width() - modifiable_widget_position_.width() -
                    border_spacing_;

  if (modifiable_widget_position_.x() > right_limit) {
    is_border_overstepped = true;
    SetModifiedWidth(right_limit);
  } else {
    is_border_overstepped = false;
  }
}

void BorderController::SetModifiedWidth(int width) {
  modifiable_widget_position_.setWidth(width);
}

void BorderController::SetModifiedHeight(int height) {
  modifiable_widget_position_.setHeight(height);
}
