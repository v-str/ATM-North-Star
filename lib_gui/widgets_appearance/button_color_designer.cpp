#include <button_color_designer.h>

#include <QPushButton>
#include <QWidget>

#include <painter.h>

ButtonColorDesigner::ButtonColorDesigner(QList<QWidget*> color_list)
    : ColorDesigner(color_list) {}

ButtonColorDesigner::~ButtonColorDesigner() {}

void ButtonColorDesigner::PaintWidgets() {
  QList<QWidget*> color_list = GetWidgetColorList();
  for (auto widget = color_list.begin(); widget != color_list.end(); ++widget) {
    Painter::ChangeButtonColor(
        static_cast<QPushButton*>(*widget), GetWidgetColor().MainColor(),
        GetWidgetColor().SecondaryColor(), GetWidgetColor().AdditionalColor());
  }
}
