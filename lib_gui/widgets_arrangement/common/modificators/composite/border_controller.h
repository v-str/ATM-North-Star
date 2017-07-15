#ifndef BORDER_CONTROLLER_H
#define BORDER_CONTROLLER_H

#include <QRect>

class QWidget;

class BorderController {
 public:
  void SetParentGeometry(const QRect& parent_size);
  void ControlModifiableWidget(QWidget* widget);

  void SetBorderSpacing(int border_spacer);

  bool IsBorderOverstepped();

 private:
  void ControlUp();
  void ControlDown();
  void ControlLeft();
  void ControlRight();

  void SetModifiedX(int x);
  void SetModifiedY(int y);
  void SetModifiedWidth(int width);
  void SetModifiedHeight(int height);

  QRect parent_size_;
  QRect modifiable_widget_position_;

  int border_spacing_ = 10;

  bool is_border_overstepped = false;
};

#endif  // BORDER_CONTROLLER_H
