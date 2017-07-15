#ifndef WIDGET_BORDER_CONTROLLER_H
#define WIDGET_BORDER_CONTROLLER_H

#include <QRect>

#include <widget_geometry_limiter.h>

class QWidget;

class WidgetBorderController {
 public:
  void SetBorderLimits(const QRect& parent_geometry);
  void ControlModifiableWidget(QWidget* widget);

  void SetBorderSpacing(int border_spacer);

  bool IsBorderOverstepped();

  QRect ParentGeometry() const;

 private:
  QRect parent_geometry_;
  QRect modifiable_widget_geometry_;

  void SetLimits(int widget_width, int widget_height);
  void PerformSideControl();

  WidgetGeometryLimiter geometry_limiter_;

  int border_spacer_ = 10;

  bool is_border_overstepped = false;
};

#endif  // WIDGET_BORDER_CONTROLLER_H
