#include <widget_border_controller.h>

#include <QRect>
#include <QWidget>

void WidgetBorderController::SetGeometryLimit(const QRect& parent_geometry) {
  parent_geometry_ = parent_geometry;
}

void WidgetBorderController::ControlWidget(QWidget* widget) {
  modifiable_widget_geometry_ = widget->geometry();

  SetLimits(widget->width(), widget->height());

  PerformSideControl();

  widget->setGeometry(modifiable_widget_geometry_);
}

void WidgetBorderController::SetBorderSpacing(int border_spacer) {
  border_spacer_ = border_spacer;
}

QRect WidgetBorderController::ParentGeometry() const {
  return parent_geometry_;
}

void WidgetBorderController::SetLimits(int widget_width, int widget_height) {
  geometry_limiter_.SetLeftSideLimit(border_spacer_);
  geometry_limiter_.SetUpSideLimit(border_spacer_);
  geometry_limiter_.SetRightSideLimit(parent_geometry_.width() -
                                      border_spacer_ - widget_width);
  geometry_limiter_.SetBottomSideLimit(parent_geometry_.height() -
                                       border_spacer_ - widget_height);
  geometry_limiter_.SetLimitWidth(parent_geometry_.width() -
                                  (2 * border_spacer_));
  geometry_limiter_.SetLimitHeight(parent_geometry_.height() -
                                   (2 * border_spacer_));
}

void WidgetBorderController::PerformSideControl() {
  int x = modifiable_widget_geometry_.x();
  int y = modifiable_widget_geometry_.y();
  int width = modifiable_widget_geometry_.width();
  int height = modifiable_widget_geometry_.height();

  if (x < geometry_limiter_.LeftSideLimit()) {
    x = geometry_limiter_.LeftSideLimit();
  }
  if (x > geometry_limiter_.RightSIdeLimit()) {
    x = geometry_limiter_.RightSIdeLimit();
  }
  if (y < geometry_limiter_.UpSideLimit()) {
    y = geometry_limiter_.UpSideLimit();
  }
  if (y > geometry_limiter_.BottomSideLimit()) {
    y = geometry_limiter_.BottomSideLimit();
  }
  if (width > geometry_limiter_.LimitWidth()) {
    x = geometry_limiter_.LeftSideLimit();
    width = geometry_limiter_.LimitWidth();
  }
  if (height > geometry_limiter_.LimitHeight()) {
    y = geometry_limiter_.UpSideLimit();
    height = geometry_limiter_.LimitHeight();
  }

  modifiable_widget_geometry_ = QRect(x, y, width, height);
}
