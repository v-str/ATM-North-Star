#ifndef WIDGET_BORDER_CONTROLLER_H
#define WIDGET_BORDER_CONTROLLER_H

#include <QRect>

class QWidget;

class WidgetBorderController {
 public:
  void SetParentGeometry(const QRect& parent_geometry);
  void ControlModifiableWidget(QWidget* widget);

  void SetBorderSpacing(int border_spacer);

  bool IsBorderOverstepped();

  QRect ParentGeometry() const;

 private:
  void ControlUp();
  void ControlDown();
  void ControlLeft();
  void ControlRight();

  void SetModifiedX(int x);
  void SetModifiedY(int y);

  QRect parent_geometry_;
  QRect modifiable_widget_geometry_;

  int border_spacer_ = 10;

  bool is_border_overstepped = false;
};

#endif  // WIDGET_BORDER_CONTROLLER_H
