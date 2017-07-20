#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <QFrame>
#include <QObject>
#include <QRect>
#include <QVBoxLayout>

#include <delta_size.h>
#include <v_group_composer.h>
#include <widget_border_controller.h>

#include <geometry_composer.h>

class QWidget;
class QPushButton;
class AtmColorDesigner;
class AtmButton;

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
  void SetScalingProperties();
  void SetButtonFrame();

  QFrame* button_frame_ = nullptr;

  AtmButton* sign_in_button_ = nullptr;
  AtmButton* registration_button_ = nullptr;
  AtmButton* demo_button_ = nullptr;

  QVBoxLayout* v_layout_ = nullptr;

  AtmColorDesigner* atm_color_designer_ = nullptr;

  DeltaSize delta_size_;
  WidgetBorderController border_controller_;

  GeometryComposer composer_;
};

#endif  // INITIAL_MENU_H
