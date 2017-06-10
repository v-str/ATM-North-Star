#include <button_color_designer.h>

#include <QPushButton>

#include <painter.h>

ButtonColorDesigner::ButtonColorDesigner(QList<QPushButton*> button_list)
    : button_list_(button_list) {}

ButtonColorDesigner::~ButtonColorDesigner() {}

void ButtonColorDesigner::PaintWidgets() {
  for (auto widget = button_list_.begin(); widget != button_list_.end();
       ++widget) {
    Painter::ChangeButtonColor(*widget, GetWidgetColor().MainColor(),
                               GetWidgetColor().SecondaryColor(),
                               GetWidgetColor().AdditionalColor());
  }
}
