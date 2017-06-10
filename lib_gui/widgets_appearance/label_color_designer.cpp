#include <label_color_designer.h>

#include <QLabel>

#include <painter.h>

LabelColorDesigner::LabelColorDesigner(QList<QLabel*> label_list)
    : label_list_(label_list) {}

LabelColorDesigner::~LabelColorDesigner() {}

void LabelColorDesigner::PaintWidgets() {
  for (auto label = label_list_.begin(); label != label_list_.end(); ++label) {
    Painter::ChangeLabelColor(*label, GetWidgetColor().MainColor());
  }
}
