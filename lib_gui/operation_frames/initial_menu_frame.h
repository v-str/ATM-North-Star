#ifndef INITIAL_MENU_FRAME_H
#define INITIAL_MENU_FRAME_H

#include <QFrame>
#include <QObject>
#include <QRect>

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
  QPushButton* sign_in_button_ = nullptr;
  AtmColorDesigner* atm_color_designer_ = nullptr;

  static QRect kSignInButton;
};

#endif  // INITIAL_MENU_FRAME_H
