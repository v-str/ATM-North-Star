#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <QFrame>
#include <QRect>
#include <QVBoxLayout>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class QWidget;
class QPushButton;
class AtmButton;
class OperationFrame;

class InitialMenu : public QFrame {
  Q_OBJECT
 public:
  explicit InitialMenu(QWidget* parent = nullptr);
  ~InitialMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 public slots:
  void ProcessDemoButtonClick();
  void ProcessRegistraionButtonClick();
  void Show();

 signals:
  void PassGeometryForExtrude(const QRect&);
  void PassGeometryForHide(const QRect&);
  void DemoButtonClicked();
  void RegistrationButtonClicked();

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void PaintWidgets();
  void SetFrameAnimation();

  void SetButtonsInitialSetting();
  void SetButtonGeometry();

  void SetButtonFrameScalingProperties();
  void SetButtonFrame();

  void SetConnections();

  QFrame* button_frame_ = nullptr;
  AtmButton* login_button_ = nullptr;
  AtmButton* registration_button_ = nullptr;
  AtmButton* demo_button_ = nullptr;
  QVBoxLayout* v_layout_ = nullptr;
  OperationFrame* operation_frame_ = nullptr;

  DeltaSize delta_size_;
  WidgetBorderController border_controller_;
  GeometryComposer composer_;

  static constexpr double kHalfOfSize = 0.5;
  static constexpr double kHalfOfHeight = 0.5;
};

#endif  // INITIAL_MENU_H
