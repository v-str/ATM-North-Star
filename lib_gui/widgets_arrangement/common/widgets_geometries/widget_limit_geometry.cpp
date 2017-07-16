#include <widget_limit_geometry.h>

void WidgetLimitGeometry::SetLeftSideLimit(int left_side_limit) {
  left_side_limit_ = left_side_limit;
}

void WidgetLimitGeometry::SetRightSideLimit(int right_side_limit) {
  right_side_limit_ = right_side_limit;
}

void WidgetLimitGeometry::SetUpSideLimit(int up_side_limit) {
  up_side_limit_ = up_side_limit;
}

void WidgetLimitGeometry::SetBottomSideLimit(int bottom_side_limit) {
  bottom_side_limit_ = bottom_side_limit;
}

void WidgetLimitGeometry::SetLimitWidth(int limit_width) {
  limit_width_ = limit_width;
}

void WidgetLimitGeometry::SetLimitHeight(int limit_height) {
  limit_height_ = limit_height;
}

int WidgetLimitGeometry::LeftSideLimit() const { return left_side_limit_; }

int WidgetLimitGeometry::RightSIdeLimit() const { return right_side_limit_; }

int WidgetLimitGeometry::UpSideLimit() const { return up_side_limit_; }

int WidgetLimitGeometry::BottomSideLimit() const {
  return bottom_side_limit_;
}

int WidgetLimitGeometry::LimitWidth() const { return limit_width_; }

int WidgetLimitGeometry::LimitHeight() const { return limit_height_; }
