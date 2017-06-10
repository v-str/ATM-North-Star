#include <color_designer.h>

#include <QWidget>

ColorDesigner::ColorDesigner(QList<QWidget*> widget_list)
    : widget_list_(widget_list) {}

ColorDesigner::~ColorDesigner() {}

void ColorDesigner::SetWidgetPalette(const WidgetColor& widget_color) {
  widget_color_ = widget_color;
}

QList<QWidget*> ColorDesigner::GetWidgetList() const { return widget_list_; }

WidgetColor ColorDesigner::GetWidgetColor() const { return widget_color_; }
