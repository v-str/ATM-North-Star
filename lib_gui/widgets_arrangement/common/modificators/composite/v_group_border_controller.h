#ifndef GROUP_BORDER_CONTROLLER_H
#define GROUP_BORDER_CONTROLLER_H

#include <QVector>

#include <border_controller.h>

class QWidget;

class VGroupBorderController : public BorderController {
 public:
  VGroupBorderController();

  void ControlGroup(QVector<QWidget*>& widget_vector);

  void SetGroupInterval(int widget_interval);

 private:
  QRect group_geometry_;

  int group_interval_ = 10;
};

#endif  // GROUP_BORDER_CONTROLLER_H
