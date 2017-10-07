#include <widget_tuner.h>

#include <atm_color_designer.h>

// set geometry of widget

WidgetTuner::WidgetTuner() : color_designer_(new AtmColorDesigner) {}

WidgetTuner::~WidgetTuner() { delete color_designer_; }

void WidgetTuner::TuneLabels(QList<QLabel *> *label_list) {
  color_designer_->PaintWidgetSet(label_list);
#ifdef WIN32
  // some code
#else
// some code for linux
#endif
}
