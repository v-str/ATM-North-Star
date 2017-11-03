#ifndef PAINTER_H
#define PAINTER_H

class QLabel;
class QPushButton;
class QString;
class QFrame;
class QMainWindow;
class QDialog;
class QCheckBox;

class Painter {
 public:
  static void ChangeLabelColor(QLabel* label, const QString& text_color);
  static void ChangeCheckBoxColor(QCheckBox* checkbox);
  static void ChangeButtonColor(QPushButton* push_button);
  static void ChangeFrameColor(QFrame* frame, const QString& color);
  static void ChangeBackground(QMainWindow* widget,
                               const QString& background_color);
  static void ChangeBackground(QDialog* widget,
                               const QString& background_color);
};

#endif  // PAINTER_H
