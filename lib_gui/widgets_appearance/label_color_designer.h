#ifndef LABEL_COLOR_DESIGNER_H
#define LABEL_COLOR_DESIGNER_H

#include <color_designer.h>

class LabelColorDesigner : public ColorDesigner {
 public:
  LabelColorDesigner(QList<QWidget*> label_list);
  ~LabelColorDesigner();

  virtual void PaintWidgets();
};

#endif  // LABEL_COLOR_DESIGNER_H
