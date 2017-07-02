#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <QFrame>
#include <QObject>
#include <QRect>

#include <widget_shifter.h>

class QWidget;
class QPushButton;
class AtmColorDesigner;

class InitialMenu : public QFrame {
  Q_OBJECT
 public:
  InitialMenu(QWidget* parent);
  ~InitialMenu();

  void SetExtraGeometryParameters(int extra_width, int extra_height);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void PaintWidgets();
  void SetInitialSetting();

  QPushButton* sign_in_button_ = nullptr;
  QPushButton* registration_button_ = nullptr;
  QPushButton* demo_button_ = nullptr;

  AtmColorDesigner* atm_color_designer_ = nullptr;

  static QRect kSignInButtonGeometry;
  static QRect kRegistrationButtonGeometry;
  static QRect kDemoButtonGeometry;

  WidgetShifter shifter_;

  int extra_width_ = 0;
  int extra_height_ = 0;
};

#endif  // INITIAL_MENU_H
