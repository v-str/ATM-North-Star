#ifndef WIDGET_COLOR_DESIGNER_H
#define WIDGET_COLOR_DESIGNER_H

#include <widget_color.h>

class WidgetColorDesigner {
 public:
  WidgetColorDesigner();

  void CustomizeColorSet(const WidgetColor& widget_color);

 private:
  WidgetColor widget_color_;
};

#endif  // WIDGET_COLOR_DESIGNER_H
