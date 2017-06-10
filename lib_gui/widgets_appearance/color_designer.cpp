#include <color_designer.h>

#include <QWidget>

ColorDesigner::ColorDesigner() {}

ColorDesigner::~ColorDesigner() {}

void ColorDesigner::SetWidgetColor(const WidgetColor& widget_color) {
  widget_color_ = widget_color;
}

WidgetColor ColorDesigner::GetWidgetColor() const { return widget_color_; }
