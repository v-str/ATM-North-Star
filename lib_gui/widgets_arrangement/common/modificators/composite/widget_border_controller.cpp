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

void WidgetBorderController::SetDistanceToBorder(int border_spacer) {
  distance_to_border_ = border_spacer;
}

void WidgetBorderController::SetLimits(int widget_width, int widget_height) {
  limit_geometry_.SetLeftSideLimit(distance_to_border_);
  limit_geometry_.SetUpSideLimit(distance_to_border_);
  limit_geometry_.SetRightSideLimit(parent_geometry_.width() -
                                    distance_to_border_ - widget_width);
  limit_geometry_.SetBottomSideLimit(parent_geometry_.height() -
                                     distance_to_border_ - widget_height);
  limit_geometry_.SetLimitWidth(parent_geometry_.width() -
                                (2 * distance_to_border_));
  limit_geometry_.SetLimitHeight(parent_geometry_.height() -
                                 (2 * distance_to_border_));
}

void WidgetBorderController::PerformSideControl() {
  int x = modifiable_widget_geometry_.x();
  int y = modifiable_widget_geometry_.y();
  int width = modifiable_widget_geometry_.width();
  int height = modifiable_widget_geometry_.height();

  if (x < limit_geometry_.LeftSideLimit()) {
    x = limit_geometry_.LeftSideLimit();
  }
  if (x > limit_geometry_.RightSIdeLimit()) {
    x = limit_geometry_.RightSIdeLimit();
  }
  if (y < limit_geometry_.UpSideLimit()) {
    y = limit_geometry_.UpSideLimit();
  }
  if (y > limit_geometry_.BottomSideLimit()) {
    y = limit_geometry_.BottomSideLimit();
  }
  if (width > limit_geometry_.LimitWidth()) {
    x = limit_geometry_.LeftSideLimit();
    width = limit_geometry_.LimitWidth();
  }
  if (height > limit_geometry_.LimitHeight()) {
    y = limit_geometry_.UpSideLimit();
    height = limit_geometry_.LimitHeight();
  }

  modifiable_widget_geometry_ = QRect(x, y, width, height);
}
