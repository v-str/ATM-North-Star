#include <widget_border_controller.h>

#include <QRect>
#include <QWidget>

void WidgetBorderController::SetParentGeometry(const QRect& parent_geometry) {
  parent_geometry_ = parent_geometry;
}

void WidgetBorderController::ControlModifiableWidget(QWidget* widget) {
  modifiable_widget_geometry_ = widget->geometry();

  ControlUp();
  ControlDown();
  ControlLeft();
  ControlRight();

  widget->setGeometry(modifiable_widget_geometry_);
}

void WidgetBorderController::SetBorderSpacing(int border_spacer) {
  border_spacer_ = border_spacer;
}

bool WidgetBorderController::IsBorderOverstepped() { return is_border_overstepped; }

QRect WidgetBorderController::ParentGeometry() const { return parent_geometry_; }

void WidgetBorderController::ControlUp() {
  int up_limit = border_spacer_;

  if (modifiable_widget_geometry_.y() < up_limit) {
    is_border_overstepped = true;
    SetModifiedY(up_limit);
  } else {
    is_border_overstepped = false;
  }
}

void WidgetBorderController::ControlDown() {
  int down_limit = parent_geometry_.height() -
                   modifiable_widget_geometry_.height() - border_spacer_;

  if (modifiable_widget_geometry_.y() > down_limit) {
    is_border_overstepped = true;
    SetModifiedY(down_limit);
  } else {
    is_border_overstepped = false;
  }
}

void WidgetBorderController::ControlLeft() {
  int left_limit = border_spacer_;

  if (modifiable_widget_geometry_.x() < left_limit) {
    is_border_overstepped = true;
    SetModifiedX(left_limit);
  } else {
    is_border_overstepped = false;
  }
}

void WidgetBorderController::ControlRight() {
  int right_limit = parent_geometry_.width() -
                    modifiable_widget_geometry_.width() - border_spacer_;

  if (modifiable_widget_geometry_.x() > right_limit) {
    is_border_overstepped = true;
    SetModifiedX(right_limit);
  } else {
    is_border_overstepped = false;
  }
}

void WidgetBorderController::SetModifiedX(int x) {
  modifiable_widget_geometry_ = QRect(x, modifiable_widget_geometry_.y(),
                                      modifiable_widget_geometry_.width(),
                                      modifiable_widget_geometry_.height());
}

void WidgetBorderController::SetModifiedY(int y) {
  modifiable_widget_geometry_ = QRect(modifiable_widget_geometry_.x(), y,
                                      modifiable_widget_geometry_.width(),
                                      modifiable_widget_geometry_.height());
}
