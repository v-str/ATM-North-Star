#ifndef ATM_COLOR_DESIGNER_H
#define ATM_COLOR_DESIGNER_H

#include <QList>

class QLabel;
class QPushButton;
class QFrame;
class QMainWindow;
class QDialog;
class QCheckBox;

class AtmColorDesigner {
 public:
  static void SetBackground(QMainWindow* main_window);
  static void SetBackground(QDialog* dialog);

  static void PaintWidgetSet(QList<QLabel*>* label_list);
  static void PaintWidgetSet(QList<QPushButton*>* button_list);
  static void PaintWidgetSet(QList<QFrame*>* frame_list);

  static void PaintSingleWidget(QLabel* label);
  static void PaintSingleWidget(QPushButton* button);
  static void PaintSingleWidget(QFrame* frame);
  static void PaintSingleWidget(QCheckBox* checkbox);

  static void PaintFrame(QFrame* frame);
};

#endif  // ATM_COLOR_DESIGNER_H
