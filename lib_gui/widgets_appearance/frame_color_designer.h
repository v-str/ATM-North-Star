#ifndef FRAME_COLOR_DESIGNER_H
#define FRAME_COLOR_DESIGNER_H

#include <color_designer.h>

class FrameColorDesigner : public ColorDesigner {
 public:
  FrameColorDesigner(QList<QWidget*> label_list);
  ~FrameColorDesigner();

  void PaintWidgets() override;
};

#endif  // FRAME_COLOR_DESIGNER_H
