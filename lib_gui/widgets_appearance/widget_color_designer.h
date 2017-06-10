#ifndef WIDGET_COLOR_DESIGNER_H
#define WIDGET_COLOR_DESIGNER_H

#include <QList>

#include <widget_color.h>

class QLabel;

class WidgetColorDesigner {
 public:
  WidgetColorDesigner();

  void CustomizeColorSet(const WidgetColor& widget_color);

  void PaintWidgetSet(QList<QLabel*> label_list) const;

 private:
  WidgetColor widget_color_;
};

#endif  // WIDGET_COLOR_DESIGNER_H
