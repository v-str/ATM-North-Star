#ifndef COLOR_DESIGNER_H
#define COLOR_DESIGNER_H

#include <QList>
#include <QString>

#include <widget_color.h>

class QWidget;

class ColorDesigner {
 public:
  ColorDesigner(QList<QWidget*> color_list);
  virtual ~ColorDesigner();

  void SetWidgetPalette(const WidgetColor& widget_color);

  virtual void PaintWidgets() = 0;

  QList<QWidget*> GetWidgetColorList() const;
  WidgetColor GetWidgetColor() const;

 private:
  QList<QWidget*> color_list_;
  WidgetColor widget_color_;
};

#endif  // COLOR_DESIGNER_H
