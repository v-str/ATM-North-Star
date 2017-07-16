#include <v_group_border_controller.h>

#include <QWidget>

VGroupBorderController::VGroupBorderController()
    : group_geometry_(QRect{0, 0, 0, 0}) {}

// void VGroupBorderController::ControlGroup(QVector<QWidget*>& widget_vector)
// {}

void VGroupBorderController::SetIntervalBetweenWidgets(
    int interval_between_widgets_pt) {
  interval_between_widgets_pt_ = interval_between_widgets_pt;
}
