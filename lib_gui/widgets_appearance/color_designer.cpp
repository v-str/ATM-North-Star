#include <color_designer.h>

#include <QWidget>

ColorDesigner::ColorDesigner(QList<QWidget*> color_list)
    : color_list_(color_list) {}

ColorDesigner::~ColorDesigner() {}

void ColorDesigner::SetWidgetPalette(const WidgetColor& widget_color) {
  widget_color_ = widget_color;
}

QList<QWidget*> ColorDesigner::GetWidgetColorList() const {
  return color_list_;
}

WidgetColor ColorDesigner::GetWidgetColor() const { return widget_color_; }
