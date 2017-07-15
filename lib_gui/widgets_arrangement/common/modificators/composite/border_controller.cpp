#include <border_controller.h>

#include <QRect>
#include <QWidget>

void BorderController::SetParentGeometry(const QRect& parent_geometry) {
  parent_geometry_ = parent_geometry;
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

QRect BorderController::ParentGeometry() const { return parent_geometry_; }

void BorderController::ControlUp() {
  int up_limit = border_spacing_;

  if (modifiable_widget_position_.y() < up_limit) {
    is_border_overstepped = true;
    SetModifiedY(up_limit);
  } else {
    is_border_overstepped = false;
  }
}

void BorderController::ControlDown() {
  int down_limit = parent_geometry_.height() -
                   modifiable_widget_position_.height() - border_spacing_;

  if (modifiable_widget_position_.y() > down_limit) {
    is_border_overstepped = true;
    SetModifiedY(down_limit);
  } else {
    is_border_overstepped = false;
  }
}

void BorderController::ControlLeft() {
  int left_limit = border_spacing_;

  if (modifiable_widget_position_.x() < left_limit) {
    is_border_overstepped = true;
    SetModifiedX(left_limit);
  } else {
    is_border_overstepped = false;
  }
}

void BorderController::ControlRight() {
  int right_limit = parent_geometry_.width() -
                    modifiable_widget_position_.width() - border_spacing_;

  if (modifiable_widget_position_.x() > right_limit) {
    is_border_overstepped = true;
    SetModifiedX(right_limit);
  } else {
    is_border_overstepped = false;
  }
}

void BorderController::SetModifiedX(int x) {
  modifiable_widget_position_ = QRect(x, modifiable_widget_position_.y(),
                                      modifiable_widget_position_.width(),
                                      modifiable_widget_position_.height());
}

void BorderController::SetModifiedY(int y) {
  modifiable_widget_position_ = QRect(modifiable_widget_position_.x(), y,
                                      modifiable_widget_position_.width(),
                                      modifiable_widget_position_.height());
}
