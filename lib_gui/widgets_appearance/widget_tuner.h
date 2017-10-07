#ifndef WIDGET_TUNER_H
#define WIDGET_TUNER_H

#include <QLabel>
#include <QList>

class AtmColorDesigner;

class WidgetTuner {
 public:
  WidgetTuner();
  ~WidgetTuner();

  void TuneLabels(QList<QLabel*>* label_list);

 private:
  AtmColorDesigner* color_designer_ = nullptr;
};

#endif  // WIDGET_TUNER_H
