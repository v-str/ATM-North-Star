#ifndef WIDGET_GEOMETRY_LIMITER_H
#define WIDGET_GEOMETRY_LIMITER_H

class WidgetGeometryLimiter {
 public:
  void SetLeftSideLimit(int left_side_limit);
  void SetRightSideLimit(int right_side_limit);
  void SetUpSideLimit(int up_side_limit);
  void SetBottomSideLimit(int bottom_side_limit);

  void SetLimitWidth(int limit_width);
  void SetLimitHeight(int limit_height);

  int LeftSideLimit() const;
  int RightSIdeLimit() const;
  int UpSideLimit() const;
  int BottomSideLimit() const;

  int LimitWidth() const;
  int LimitHeight() const;

 private:
  int left_side_limit_ = 0;
  int right_side_limit_ = 0;
  int up_side_limit_ = 0;
  int bottom_side_limit_ = 0;
  int limit_width_ = 0;
  int limit_height_ = 0;
};

#endif  // WIDGET_GEOMETRY_LIMITER_H
