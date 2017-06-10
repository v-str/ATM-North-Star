#ifndef FRAME_COLOR_DESIGNER_H
#define FRAME_COLOR_DESIGNER_H

#include <QList>

#include <color_designer.h>

class QFrame;

class FrameColorDesigner : public ColorDesigner {
 public:
  FrameColorDesigner(QList<QFrame*> frame_list);
  ~FrameColorDesigner();

  void PaintWidgets() override;

 private:
  QList<QFrame*> frame_list_;
};

#endif  // FRAME_COLOR_DESIGNER_H
