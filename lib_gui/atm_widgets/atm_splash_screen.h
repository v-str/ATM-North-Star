#ifndef ATM_SPLASH_SCREEN_H
#define ATM_SPLASH_SCREEN_H

#include <QMainWindow>

class TextColorSwapper;
class ExitDialog;
class QString;
class QTimer;
class WidgetColor;

namespace Ui {
class AtmSplashScreen;
}

class AtmSplashScreen : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmSplashScreen(QWidget* parent = nullptr);
  ~AtmSplashScreen();

  void SetCompanyName(const QString& atm_company_name = "Default Name");
  void SetSplashScreenAppearance(const QString& main_color = "yellow",
                                 const QString& secondary_color = "red",
                                 const QString& additional_color = "blue");
  void SetAtmBlinkColor(const QString& color_one = "black",
                        const QString& color_two = "grey");
  void SetBackgroundImage(
      const QString& background_image = ":/images/black_background.jpg");
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
  void ColorizeLabels(const WidgetColor& widget_color);
  void ColorizeButtons(const WidgetColor& widget_color);
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
};

#endif  // ATM_SPLASH_SCREEN_H
