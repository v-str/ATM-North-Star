#include <frame_color_designer.h>

#include <QList>
#include <QWidget>

FrameColorDesigner::FrameColorDesigner(QList<QWidget*> label_list)
    : ColorDesigner(label_list) {}

FrameColorDesigner::~FrameColorDesigner() {}
