#ifndef WIDGET_BORDER_CONTROLLER_H
#define WIDGET_BORDER_CONTROLLER_H

#include <QRect>

#include <widget_limit_geometry.h>

class QWidget;

class WidgetBorderController {
 public:
  void SetGeometryLimit(const QRect& parent_geometry);
  void ControlWidget(QWidget* widget);

  void SetDistanceToBorder(int border_spacer);

 private:
  void SetLimits(int widget_width, int widget_height);
  void PerformSideControl();

  QRect parent_geometry_;
  QRect modifiable_widget_geometry_;

  WidgetLimitGeometry geometry_limiter_;

  int distance_to_border_ = 10;
};

#endif  // WIDGET_BORDER_CONTROLLER_H
