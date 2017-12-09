#ifndef GRAPHICAL_INITIAL_MENU_H
#define GRAPHICAL_INITIAL_MENU_H

#include <base_atm_frame.h>

#include <QRect>
#include <QVBoxLayout>

#include <widget_border_controller.h>

class QWidget;
class QPushButton;
class AtmButton;
class FontSizeGenerator;

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
  void ChangeGeometry() override;

  void ProcessDemoButtonClick();
  void ProcessRegistraionButtonClick();
  void ProcessLoginButtonClick();
  void ShowFirstTime();
  void ShowMenu();

 private:
  void PaintWidgets();
  void TuneButtons();
  void SetButtons();
  void InitializeFontGenerator();
  void CopyLoginButtonAppearanceToRegistrationButton();
  void SetConnections();

  AtmButton* login_button_ = nullptr;
  AtmButton* registration_button_ = nullptr;

  FontSizeGenerator* font_size_generator_ = nullptr;

  WidgetBorderController border_controller_;
  static const int kHeightBtwButtons = 10;
};

#endif  // GRAPHICAL_INITIAL_MENU_H
