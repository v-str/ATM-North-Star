#include <frame_color_designer.h>

#include <QFrame>
#include <QWidget>

#include <painter.h>

FrameColorDesigner::FrameColorDesigner(QList<QWidget*> label_list)
    : ColorDesigner(label_list) {}

FrameColorDesigner::~FrameColorDesigner() {}

void FrameColorDesigner::PaintWidgets() {
  QList<QWidget*> frame_list = GetWidgetList();
  for (auto frame = frame_list.begin(); frame != frame_list.end(); ++frame) {
    Painter::ChangeFrameColor(static_cast<QFrame*>(*frame),
                              GetWidgetColor().MainColor());
  }
}
