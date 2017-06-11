#include <widget_color_designer.h>

#include <QFrame>
#include <QLabel>
#include <QPushButton>

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

void WidgetColorDesigner::PaintWidgetSet(
    QList<QPushButton*> button_list) const {
  for (auto button = button_list.begin(); button != button_list.end();
       ++button) {
    Painter::ChangeButtonColor(*button, widget_color_.MainColor(),
                               widget_color_.SecondaryColor(),
                               widget_color_.AdditionalColor());
  }
}

void WidgetColorDesigner::PaintWidgetSet(QList<QFrame*> frame_list) const {}
