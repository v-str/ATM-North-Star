﻿#ifndef BORDER_CONTROLLER_H
#define BORDER_CONTROLLER_H

#include <QRect>

class QWidget;

class BorderController {
 public:
  void SetParentSize(const QRect& parent_size);
  void ControlModifiableWidget(QWidget* widget);

  void SetBorderSpacing(int border_spacer);

 private:
  void ControlUp();
  void ControlDown();
  void ControlLeft();
  void ControlRight();

  QRect parent_size_;
  QRect modifiable_widget_position_;

  int border_spacer_ = 5;
};

#endif  // BORDER_CONTROLLER_H
