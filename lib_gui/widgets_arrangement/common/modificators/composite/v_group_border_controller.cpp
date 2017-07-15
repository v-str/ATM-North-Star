#include <v_group_border_controller.h>

#include <QWidget>

void VGroupBorderController::ControlGroup(QVector<QWidget*>& widget_vector) {}

void VGroupBorderController::SetGroupInterval(int widget_interval) {
  group_interval_ = widget_interval;
}
