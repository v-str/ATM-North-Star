#ifndef GROUP_BORDER_CONTROLLER_H
#define GROUP_BORDER_CONTROLLER_H

#include <QVector>

#include <border_controller.h>

class QWidget;

class GroupBorderController : public BorderController {
 public:
  enum GroupMode { kVertical, kHorizontal };

  void SetGroupMode(GroupMode group_mode);

  void ControlGroup(QVector<QWidget*>& widget_vector);

  void SetWidgetInterval(int widget_interval);

 private:
  GroupMode group_mode_;

  int widget_interval_ = 10;
};

#endif  // GROUP_BORDER_CONTROLLER_H
