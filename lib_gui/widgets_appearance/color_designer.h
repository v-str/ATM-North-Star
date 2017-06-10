#ifndef COLOR_DESIGNER_H
#define COLOR_DESIGNER_H

#include <QString>

#include <widget_color.h>

class ColorDesigner {
 public:
  ColorDesigner();
  virtual ~ColorDesigner();

  void SetWidgetColor(const WidgetColor& widget_color);

  virtual void PaintWidgets() = 0;

  WidgetColor GetWidgetColor() const;

 private:
  WidgetColor widget_color_;
};

#endif  // COLOR_DESIGNER_H
