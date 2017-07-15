#include <group_border_controller.h>

#include <QWidget>

void GroupBorderController::SetGroupMode(
    GroupBorderController::GroupMode group_mode) {
  group_mode_ = group_mode;
}

void GroupBorderController::ControlGroup(QVector<QWidget*>& widget_vector) {
  // Control head of group
  // if (IsBorderOverstepped()) {
  // control body of the group
  // switch (group_mode) {
  // case kVertical: control vertical group
  // break;
  // case kGorizontal: control gorizontal group
  // break;
}

void GroupBorderController::SetWidgetInterval(int widget_interval) {
  widget_interval_ = widget_interval;
}
