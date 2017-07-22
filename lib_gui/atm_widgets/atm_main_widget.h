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
  void ShowDemoMenu();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetConnections();
  void SetInitialSettings();

  void SetBackgroundColor();
  void SetImages();

  void SetWidgetProperties();
  void SetInitialFrameArrangement();
  void SetTimeLabelArrangement();
  void RunTimers();
  void PaintWidgets();
  void InitializeObject();
  void ComputeExtraSize();

  Ui::AtmMainWidget* ui = nullptr;
  QTimer* time_timer_ = nullptr;
  InitialMenu* initial_menu_ = nullptr;
  DemoMenu* demo_menu_ = nullptr;

  AtmColorDesigner color_designer_;
  GeometryComposer composer_;
};

#endif  // ATM_MAIN_WIDGET_H
