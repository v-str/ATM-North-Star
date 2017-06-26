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

  void SetExtraGeometryParameters(int extra_width, int extra_height);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void PaintWidgets();

  QPushButton* sign_in_button_ = nullptr;
  AtmColorDesigner* atm_color_designer_ = nullptr;

  static QRect kSignInButton;

  int extra_width_ = 0;
  int extra_height_ = 0;
};

#endif  // INITIAL_MENU_FRAME_H
