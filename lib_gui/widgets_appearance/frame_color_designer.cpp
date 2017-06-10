#include <frame_color_designer.h>

#include <QFrame>

#include <painter.h>

FrameColorDesigner::FrameColorDesigner(QList<QFrame*> frame_list)
    : frame_list_(frame_list) {}

FrameColorDesigner::~FrameColorDesigner() {}

void FrameColorDesigner::PaintWidgets() {
  for (auto frame = frame_list_.begin(); frame != frame_list_.end(); ++frame) {
    Painter::ChangeFrameColor(*frame, GetWidgetColor().MainColor());
  }
}
