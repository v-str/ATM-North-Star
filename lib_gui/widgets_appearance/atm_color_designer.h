#ifndef ATM_COLOR_DESIGNER_H
#define ATM_COLOR_DESIGNER_H

#include <QList>

#include <widget_color.h>

class QLabel;
class QPushButton;
class QFrame;

class AtmColorDesigner {
 public:
  AtmColorDesigner();

  void ConfigureWidgetColorSet(const WidgetColor& widget_color);

  void PaintWidgetSet(QList<QLabel*> label_list) const;
  void PaintWidgetSet(QList<QPushButton*> button_list) const;
  void PaintWidgetSet(QList<QFrame*> frame_list) const;

 private:
  WidgetColor widget_color_;
};

#endif  // ATM_COLOR_DESIGNER_H
