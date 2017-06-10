#include <widget_color_designer.h>

#include <QLabel>

#include <painter.h>

WidgetColorDesigner::WidgetColorDesigner() {}

void WidgetColorDesigner::CustomizeColorSet(const WidgetColor& widget_color) {
  widget_color_ = widget_color;
}

void WidgetColorDesigner::PaintWidgetSet(QList<QLabel*> label_list) const {
  for (auto label = label_list.begin(); label != label_list.end(); ++label) {
    Painter::ChangeLabelColor(*label, widget_color_.MainColor());
  }
}
