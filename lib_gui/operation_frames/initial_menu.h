#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <QFrame>
#include <QObject>
#include <QRect>

#include <delta_size.h>
#include <widget_shifter.h>

class QWidget;
class QPushButton;
class AtmColorDesigner;

class InitialMenu : public QFrame {
  Q_OBJECT
 public:
  InitialMenu(QWidget* parent);
  ~InitialMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

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
  DeltaSize delta_size_;
};

#endif  // INITIAL_MENU_H
