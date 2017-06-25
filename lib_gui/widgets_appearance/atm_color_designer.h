#ifndef ATM_COLOR_DESIGNER_H
#define ATM_COLOR_DESIGNER_H

#include <QList>

class QLabel;
class QPushButton;
class QFrame;
class QMainWindow;
class QDialog;
class QString;

class AtmColorDesigner {
 public:
  AtmColorDesigner();

  void SetBackgroundColor(QMainWindow* main_window,
                          const QString& background_color);
  void SetBackgroundColor(QDialog* dialog, const QString& background_color);

  void PaintWidgetSet(QList<QLabel*> label_list) const;
  void PaintWidgetSet(QList<QPushButton*> button_list) const;
  void PaintWidgetSet(QList<QFrame*> frame_list) const;
};

#endif  // ATM_COLOR_DESIGNER_H
