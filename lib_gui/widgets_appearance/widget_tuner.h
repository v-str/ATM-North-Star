#ifndef WIDGET_TUNER_H
#define WIDGET_TUNER_H

#include <QLabel>
#include <QPair>
#include <QRect>

#include <widget_font.h>

class AtmColorDesigner;

class WidgetTuner {
 public:
  void TuneLabel(QLabel* label, Qt::AlignmentFlag alignment,
                 const QPair<QRect, WidgetFont>& label_characteristic);
};

#endif  // WIDGET_TUNER_H
