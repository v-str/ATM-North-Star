#ifndef ATM_SPLASH_SCREEN_H
#define ATM_SPLASH_SCREEN_H

#include <QMainWindow>

#include <atm_color_designer.h>
#include <splash_screen_composer.h>

class TextColorSwapper;
class ExitDialog;
class QString;
class QTimer;
class TimeLabel;
class DateLabel;

namespace Ui {
class AtmSplashScreen;
}

class AtmSplashScreen : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmSplashScreen(QWidget* parent = nullptr);
  ~AtmSplashScreen();

  void SetCompanyName(const QString& atm_company_name);

 signals:
  void Exit();
  void EnterIsPressed();
  void PassPosition(const QRect& pos);
  void PassPositionForAnimation(const QRect& pos);
  void SizeWindowModified();

 public slots:
  void UnlockFixedGeometry();
  void BlinkAtmLabelColor();

  void ShowExitWidget();

 protected:
  void keyPressEvent(QKeyEvent* event);
  void resizeEvent(QResizeEvent* event);

 private:
  void SetInitialSettings();
  void InitializeObjects();
  void PaintWidgets();
  void SetBackgroundColor();
  void SetImages();

  void SetWidgetProperties();

  void SetConnections();

  void RunTimers();

  void ProcessEnterKey();
  void ComputeNewGeometry();
  void ResizeWidgets();

  Ui::AtmSplashScreen* ui = nullptr;
  QTimer* color_swap_timer_ = nullptr;
  TextColorSwapper* text_color_swapper_ = nullptr;
  ExitDialog* exit_dialog_ = nullptr;

  TimeLabel* time_label_ = nullptr;
  DateLabel* date_label_ = nullptr;

  AtmColorDesigner color_designer_;
  SplashScreenSizeComposer composer_;

  static const int kOneSecond = 1000;
  static const int kTimerValue = 350;
  static const int kWidgetWidth = 600;
  static const int kWidgetHeight = 400;
};

#endif  // ATM_SPLASH_SCREEN_H
