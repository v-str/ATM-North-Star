#ifndef BORDER_CONTROLLER_H
#define BORDER_CONTROLLER_H

#include <QPoint>

class QWidget;

class BorderController {
 public:
  void SetParentSize(const QPoint& parent_size);
  void ControlModifiableWidget(QWidget* widget);

 private:
  QPoint parent_size_;
};

#endif  // BORDER_CONTROLLER_H
