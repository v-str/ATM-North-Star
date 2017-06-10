#ifndef LABEL_COLOR_DESIGNER_H
#define LABEL_COLOR_DESIGNER_H

#include <QList>

#include <color_designer.h>

class QLabel;

class LabelColorDesigner : public ColorDesigner {
 public:
  LabelColorDesigner(QList<QLabel*> label_list);
  ~LabelColorDesigner();

  void PaintWidgets() override;

 private:
  QList<QLabel*> label_list_;
};

#endif  // LABEL_COLOR_DESIGNER_H
