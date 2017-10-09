#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QFrame>
#include <QMainWindow>

#include <atm_color_designer.h>
#include <delta_size.h>
#include <geometry_composer.h>
#include <main_widget_composer.h>

class QString;
class ApplicationColor;
class QTimer;
class GraphicalInitialMenu;
class GraphicalDescriptionMenu;
class GraphicalRegistrationMenu;
class GraphicalLoginMenu;
class TimeLabel;
class DateLabel;

namespace Ui {
class AtmMainWidget;
}

class AtmMainWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmMainWidget(QWidget* parent = nullptr);
  ~AtmMainWidget();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetInitialSettings();
  void InitializeObject();
  void PaintWidgets();
  void SetBackgroundColor();
  void SetImages();
  void SetWidgetProperties();
  void SetConnections();
  void RunTimers();
  void SetArrangement();
  void SetTimeDateArrangement();
  void ComputeDeltaSize();

  Ui::AtmMainWidget* ui = nullptr;
  GraphicalInitialMenu* initial_menu_ = nullptr;
  GraphicalRegistrationMenu* registration_menu_ = nullptr;
  GraphicalLoginMenu* login_menu_ = nullptr;

  TimeLabel* time_label_ = nullptr;
  DateLabel* date_label_ = nullptr;

  AtmColorDesigner color_designer_;

  GeometryComposer composer_;
  MainWidgetComposer main_composer_;

  int delta_width_ = 0;
  int delta_height_ = 0;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;

  static const int kAppWidth = 600;
  static const int kAppHeight = 400;

  static const int kOneSecond = 1;
};

#endif  // ATM_MAIN_WIDGET_H
