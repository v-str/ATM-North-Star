#ifndef ATM_SPLASH_SCREEN_H
#define ATM_SPLASH_SCREEN_H

#include <QMainWindow>

#include <widget_color_designer.h>

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

  void SetCompanyName(const QString& atm_company_name = "Default Name");
  void SetSplashScreenAppearance(const QString& main_color,
                                 const QString& secondary_color,
                                 const QString& additional_color);
  void SetAtmBlinkColor(const QString& color_one = "black",
                        const QString& color_two = "grey");

  void SetBackgroundColor(const QString& background_color = "black");

 signals:
  void BlinkColor();
  void Exit();
  void PassPositionWhenEnterPressed(const QRect& end_value);

 public slots:
  void AtmBlinkColor();
  void ChangeTimeDate();
  void ShowExitWidget();

 protected:
  void keyPressEvent(QKeyEvent* event);

 private:
  void InitialSettings();
  void SetWidgetAppearance();
  void PaintWidgets();
  void SetConnections();
  void InitializeObjects();
  void RunTimers();
  void BlockKeys();

  Ui::AtmSplashScreen* ui = nullptr;
  QTimer* color_swap_timer_ = nullptr;
  QTimer* time_date_timer_ = nullptr;
  TextColorSwapper* color_swapper_ = nullptr;
  ExitDialog* exit_dialog_ = nullptr;

  QString blink_color_one_ = "black";
  QString blink_color_two_ = "grey";

  WidgetColorDesigner color_designer_;
};

#endif  // ATM_SPLASH_SCREEN_H
