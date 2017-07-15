#include <widget_geometry_limiter.h>

void WidgetGeometryLimiter::SetLeftSideLimit(int left_side_limit) {
  left_side_limit_ = left_side_limit;
}

void WidgetGeometryLimiter::SetRightSideLimit(int right_side_limit) {
  right_side_limit_ = right_side_limit;
}

void WidgetGeometryLimiter::SetUpSideLimit(int up_side_limit) {
  up_side_limit_ = up_side_limit;
}

void WidgetGeometryLimiter::SetBottomSideLimit(int bottom_side_limit) {
  bottom_side_limit_ = bottom_side_limit;
}

void WidgetGeometryLimiter::SetLimitWidth(int limit_width) {
  limit_width_ = limit_width;
}

void WidgetGeometryLimiter::SetLimitHeight(int limit_height) {
  limit_height_ = limit_height;
}

int WidgetGeometryLimiter::LeftSideLimit() const { return left_side_limit_; }

int WidgetGeometryLimiter::RightSIdeLimit() const { return right_side_limit_; }

int WidgetGeometryLimiter::UpSideLimit() const { return up_side_limit_; }

int WidgetGeometryLimiter::BottomSideLimit() const {
  return bottom_side_limit_;
}

int WidgetGeometryLimiter::LimitWidth() const { return limit_width_; }

int WidgetGeometryLimiter::LimitHeight() const { return limit_height_; }
