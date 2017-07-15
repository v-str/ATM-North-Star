#ifndef BORDER_CONTROLLER_H
#define BORDER_CONTROLLER_H

#include <QRect>

class QWidget;

class BorderController {
 public:
  void SetParentSize(const QRect& parent_size);
  void ControlModifiableWidget(QWidget* widget);

 private:
  void ControlUp();
  void ControlDown();
  void ControlLeft();
  void ControlRight();

  QRect parent_size_;
  QRect modifiable_widget_position_;

  static const int kBorderSpacer = 5;
};

#endif  // BORDER_CONTROLLER_H
