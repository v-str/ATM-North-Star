#include <v_group_border_controller.h>

#include <QWidget>

VGroupBorderController::VGroupBorderController()
    : group_geometry_(QRect{0, 0, 0, 0}) {}

void VGroupBorderController::ControlGroup(QVector<QWidget*>& widget_vector) {}

void VGroupBorderController::SetGroupInterval(int widget_interval) {
  group_interval_ = widget_interval;
}
