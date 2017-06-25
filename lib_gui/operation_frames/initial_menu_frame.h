#ifndef INITIAL_MENU_FRAME_H
#define INITIAL_MENU_FRAME_H

#include <QFrame>
#include <QObject>

class QWidget;
class QPushButton;
class AtmColorDesigner;

class InitialMenuFrame : public QFrame {
  Q_OBJECT
 public:
  InitialMenuFrame(QWidget* parent);
  ~InitialMenuFrame();

  void PaintWidgets();

 private:
  QPushButton* example_button_ = nullptr;
  AtmColorDesigner* atm_color_designer_ = nullptr;
};

#endif  // INITIAL_MENU_FRAME_H
