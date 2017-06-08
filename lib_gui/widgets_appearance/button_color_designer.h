#ifndef BUTTON_COLOR_DESIGNER_H
#define BUTTON_COLOR_DESIGNER_H

#include <color_designer.h>

class ButtonColorDesigner : public ColorDesigner {
 public:
  ButtonColorDesigner(QList<QWidget*> color_list);
  ~ButtonColorDesigner();

  void PaintWidgets() override;
};

#endif  // BUTTON_COLOR_DESIGNER_H
