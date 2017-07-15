#ifndef BORDER_CONTROLLER_H
#define BORDER_CONTROLLER_H

#include <QPoint>

class QWidget;

class BorderController {
 public:
  void SetParentSize(const QPoint& parent_size);
  void ControlModifiableWidget(QWidget* widget);

 private:
  void ControlUp();
  void ControlDown();
  void ControlLeft();
  void ControlRight();

  QPoint parent_size_;
  QPoint modifiable_widget_position_;
};

#endif  // BORDER_CONTROLLER_H
