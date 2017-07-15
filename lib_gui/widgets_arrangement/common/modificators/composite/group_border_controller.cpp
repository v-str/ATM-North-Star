#include <group_border_controller.h>

#include <QWidget>

void GroupBorderController::SetGroupMode(
    GroupBorderController::GroupMode group_mode) {
  group_mode_ = group_mode;
}

void GroupBorderController::ControlGroup(QVector<QWidget*>& widget_vector) {
  ControlGroupHead(widget_vector[0]);

  if (IsBorderOverstepped()) {
    switch (group_mode_) {
      case kVertical:
        for (int i = 1; i < widget_vector.size(); ++i) {
        }
        break;
      case kHorizontal:
        for (int i = 1; i < widget_vector.size(); ++i) {
        }
        break;
    }
  }
}

void GroupBorderController::SetWidgetInterval(int widget_interval) {
  widget_interval_ = widget_interval;
}

void GroupBorderController::ControlGroupHead(QWidget* widget) {
  ControlModifiableWidget(widget);
}
