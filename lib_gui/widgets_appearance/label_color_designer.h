#ifndef LABEL_COLOR_DESIGNER_H
#define LABEL_COLOR_DESIGNER_H

#include <color_designer.h>

class LabelColorDesigner : public ColorDesigner {
 public:
  LabelColorDesigner(QList<QWidget*> label_list);
  ~LabelColorDesigner();

  void PaintWidgets() override;
};

#endif  // LABEL_COLOR_DESIGNER_H
