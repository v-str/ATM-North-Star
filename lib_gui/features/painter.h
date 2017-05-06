#ifndef PAINTER_H
#define PAINTER_H

class QLabel;
class QPushButton;
class QString;
class QFrame;

class Painter {
 public:
  static void ChangeLabelColor(QLabel* label, const QString& text_color);
  static void ChangeButtonColor(QPushButton* push_button,
                                const QString& main_color,
                                const QString& additional_color);
  static void ChangeFrameColor(QFrame* frame, const QString& color);
};

#endif  // PAINTER_H
