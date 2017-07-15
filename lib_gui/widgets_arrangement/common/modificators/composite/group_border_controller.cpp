#include <group_border_controller.h>

#include <QWidget>

void GroupBorderController::ControlGroup(QVector<QWidget*>& widget_vector) {}

void GroupBorderController::SetWidgetInterval(int widget_interval) {
  widget_interval_ = widget_interval;
}
