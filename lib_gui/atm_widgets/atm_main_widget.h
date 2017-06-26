#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QMainWindow>

#include <QRect>

#include <atm_color_designer.h>

class QPaintEvent;
class QString;
class ApplicationColor;
class QTimer;
class InitialMenuFrame;

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
  InitialMenuFrame* initial_frame_ = nullptr;

  AtmColorDesigner color_designer_;

  static QRect kTimeLabel;
  static QRect kMainFrame;
  static QRect kSecondaryFrame;

  static const int kWidth = 600;
  static const int kHeight = 400;

  int extra_width_ = 0;
  int extra_height_ = 0;
};

#endif  // ATM_MAIN_WIDGET_H
