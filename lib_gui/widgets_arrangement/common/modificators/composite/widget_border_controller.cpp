#include <widget_border_controller.h>

#include <QRect>
#include <QWidget>

void WidgetBorderController::SetBorderLimits(const QRect& parent_geometry) {
  parent_geometry_ = parent_geometry;
}

void WidgetBorderController::ControlModifiableWidget(QWidget* widget) {
  modifiable_widget_geometry_ = widget->geometry();

  SetLimits(widget->width(), widget->height());

  PerformSideControl();

  widget->setGeometry(modifiable_widget_geometry_);
}

void WidgetBorderController::SetBorderSpacing(int border_spacer) {
  border_spacer_ = border_spacer;
}

bool WidgetBorderController::IsBorderOverstepped() {
  return is_border_overstepped;
}

QRect WidgetBorderController::ParentGeometry() const {
  return parent_geometry_;
}

void WidgetBorderController::SetLimits(int widget_width, int widget_height) {
  left_side_limit_ = border_spacer_;
  up_side_limit_ = border_spacer_;

  right_side_limit_ = parent_geometry_.width() - border_spacer_ - widget_width;
  bottom_side_limit_ =
      parent_geometry_.height() - border_spacer_ - widget_height;

  width_limit_ = parent_geometry_.width() - (2 * border_spacer_);
  height_limit_ = parent_geometry_.height() - (2 * border_spacer_);
}

void WidgetBorderController::PerformSideControl() {
  int x = modifiable_widget_geometry_.x();
  int y = modifiable_widget_geometry_.y();
  int width = modifiable_widget_geometry_.width();
  int height = modifiable_widget_geometry_.height();

  if (x < left_side_limit_) {
    x = left_side_limit_;
  }
  if (x > right_side_limit_) {
    x = right_side_limit_;
  }
  if (y < up_side_limit_) {
    y = up_side_limit_;
  }
  if (y > bottom_side_limit_) {
    y = bottom_side_limit_;
  }
  if (width > width_limit_) {
    x = left_side_limit_;
    width = width_limit_;
  }
  if (height > height_limit_) {
    y = up_side_limit_;
    height = height_limit_;
  }

  modifiable_widget_geometry_ = QRect(x, y, width, height);
}
