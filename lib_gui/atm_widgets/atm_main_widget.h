#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QMainWindow>

#include <atm_color_designer.h>
#include <geometry_composer.h>

class QPaintEvent;
class QString;
class ApplicationColor;
class QTimer;
class InitialMenu;
class DemoMenu;
class RegistrationMenu;
class LoginMenu;

namespace Ui {
class AtmMainWidget;
}

class AtmMainWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmMainWidget(QWidget* parent = nullptr);
  ~AtmMainWidget();

 public slots:
  void MaximizeButtonClicked(bool);
  void TickTime();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetConnections();
  void SetInitialSettings();

  void SetBackground();
  void SetImages();

  void SetWidgetProperties();
  void SetFrameArrangement();
  void SetTimeLabelArrangement();
  void RunTimers();
  void PaintWidgets();
  void InitializeObject();
  void ComputeExtraSize();

  Ui::AtmMainWidget* ui = nullptr;
  QTimer* time_timer_ = nullptr;
  InitialMenu* initial_menu_ = nullptr;
  DemoMenu* demo_menu_ = nullptr;
  RegistrationMenu* registration_menu_ = nullptr;
  LoginMenu* login_menu_ = nullptr;

  AtmColorDesigner color_designer_;
  GeometryComposer composer_;

  int delta_width_ = 0;
  int delta_height_ = 0;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;

  static const int kAppWidth = 600;
  static const int kAppHeight = 400;

  static const int kOneSecond = 1;
};

#endif  // ATM_MAIN_WIDGET_H
