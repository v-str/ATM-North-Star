#ifndef GROUP_BORDER_CONTROLLER_H
#define GROUP_BORDER_CONTROLLER_H

#include <QVector>

#include <widget_border_controller.h>

class QWidget;

class VGroupBorderController : public WidgetBorderController {
 public:
  VGroupBorderController();

  void ControlGroup(QVector<QWidget*> widget_vector);

  void SetIntervalBetweenWidgets(int interval_between_widgets_pt);

 private:
  QRect group_geometry_;

  int interval_between_widgets_pt_ = 10;
};

#endif  // GROUP_BORDER_CONTROLLER_H
