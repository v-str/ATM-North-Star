#ifndef GRAPHICAL_INITIAL_MENU_H
#define GRAPHICAL_INITIAL_MENU_H

#include <base_atm_frame.h>

#include <QRect>
#include <QVBoxLayout>

#include <delta_size.h>
#include <geometry_composer.h>
#include <initial_menu_composer.h>
#include <widget_border_controller.h>

class QWidget;
class QPushButton;
class AtmButton;

class GraphicalInitialMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalInitialMenu(QWidget* parent = nullptr);
  ~GraphicalInitialMenu();

 signals:
  void DemoButtonClicked();
  void RegistrationButtonClicked();
  void LoginButtonClicked();

 public slots:
  void ChangeGeometry(const DeltaSize& delta_size) override;

  void ProcessDemoButtonClick();
  void ProcessRegistraionButtonClick();
  void ProcessLoginButtonClick();
  void ShowFirstTime();
  void ShowMenu();

 private:
  void PaintWidgets();
  void TuneButtons();
  void SetButtonFrame();
  void SetConnections();

  QFrame* button_frame_ = nullptr;
  AtmButton* login_button_ = nullptr;
  AtmButton* registration_button_ = nullptr;
  QVBoxLayout* v_layout_ = nullptr;

  WidgetBorderController border_controller_;
  InitialMenuComposer menu_composer_;
};

#endif  // GRAPHICAL_INITIAL_MENU_H
