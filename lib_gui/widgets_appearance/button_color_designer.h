#ifndef BUTTON_COLOR_DESIGNER_H
#define BUTTON_COLOR_DESIGNER_H

#include <QList>

#include <color_designer.h>

class QPushButton;

class ButtonColorDesigner : public ColorDesigner {
 public:
  ButtonColorDesigner(QList<QPushButton*> button_list);
  ~ButtonColorDesigner();

  void PaintWidgets() override;

 private:
  QList<QPushButton*> button_list_;
};

#endif  // BUTTON_COLOR_DESIGNER_H
