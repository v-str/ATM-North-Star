#include <label_color_designer.h>

#include <QLabel>
#include <QWidget>

#include <painter.h>

LabelColorDesigner::LabelColorDesigner(QList<QWidget*> label_list)
    : ColorDesigner(label_list) {}

LabelColorDesigner::~LabelColorDesigner() {}

void LabelColorDesigner::PaintWidgets() {
  QList<QWidget*> label_list = GetWidgetList();
  for (auto label = label_list.begin(); label != label_list.end(); ++label) {
    Painter::ChangeLabelColor(static_cast<QLabel*>(*label),
                              GetWidgetColor().MainColor());
  }
}
