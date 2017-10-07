#include <widget_tuner.h>

#include <atm_color_designer.h>

void WidgetTuner::TuneLabel(
    QLabel *label, Qt::AlignmentFlag alignment,
    const QPair<QRect, WidgetFont> &label_characteristic) {
  label->setGeometry(label_characteristic.first);
  label->setAlignment(alignment);
  label->setFont(label_characteristic.second.GetFont());
}
