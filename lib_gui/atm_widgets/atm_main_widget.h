#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QMainWindow>

#include <atm_color_designer.h>
#include <delta_size.h>

class QPaintEvent;
class QString;
class ApplicationColor;
class QTimer;
class InitialMenu;

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

  void SetBackgroundColor();
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

  AtmColorDesigner color_designer_;
  DeltaSize delta_size_;

  static const int kWidth = 600;
  static const int kHeight = 400;
};

#endif  // ATM_MAIN_WIDGET_H
