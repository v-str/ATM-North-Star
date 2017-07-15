#include <v_group_border_controller.h>

#include <QWidget>

void VGroupBorderController::ControlGroup(QVector<QWidget*>& widget_vector) {}

void VGroupBorderController::SetWidgetInterval(int widget_interval) {
  widget_interval_ = widget_interval;
}
