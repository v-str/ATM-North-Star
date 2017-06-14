#ifndef ATM_SPLASH_SCREEN_H
#define ATM_SPLASH_SCREEN_H

#include <QMainWindow>

#include <atm_color_designer.h>
#include <splash_screen_size_composer.h>

class TextColorSwapper;
class ExitDialog;
class QString;
class QTimer;

namespace Ui {
class AtmSplashScreen;
}

class AtmSplashScreen : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmSplashScreen(QWidget* parent = nullptr);
  ~AtmSplashScreen();

  void SetCompanyName(const QString& atm_company_name);

  void SetSplashScreenAppearance(const QString& main_color,
                                 const QString& secondary_color,
                                 const QString& additional_color);
  void SetAtmBlinkColor(const QString& color_one, const QString& color_two);
  void SetBackgroundColor(const QString& background_color);

 signals:
  void Exit();
  void EnterIsPressed();
  void PassPositionWhenEnterPressed(const QRect& end_value);

 public slots:
  void UnlockFixedGeometry();
  void BlinkAtmLabelColor();
  void ChangeTimeDate();
  void ShowExitWidget();

 protected:
  void keyPressEvent(QKeyEvent* event);
  void resizeEvent(QResizeEvent* event);

 private:
  void SetInitialSettings();
  void SetWidgetAppearance();
  void PaintWidgets();
  void SetConnections();
  void InitializeObjects();
  void RunTimers();
  void BlockKeys();
  void ProcessKeyEnterPressing();
  void ComputeNewGeometry();
  void ResizeWidgets();

  Ui::AtmSplashScreen* ui = nullptr;
  QTimer* color_swap_timer_ = nullptr;
  QTimer* time_date_timer_ = nullptr;
  TextColorSwapper* color_swapper_ = nullptr;
  ExitDialog* exit_dialog_ = nullptr;

  AtmColorDesigner color_designer_;
  SplashScreenSizeComposer size_composer_;
};

#endif  // ATM_SPLASH_SCREEN_H
