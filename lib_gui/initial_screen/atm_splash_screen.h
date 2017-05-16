#ifndef ATM_SPLASH_SCREEN_H
#define ATM_SPLASH_SCREEN_H

#include <QMainWindow>

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
  void SetColor(const QString& main_color = "black",
                const QString& secondary_color = "grey",
                const QString& additional_color = "blue");
  void SetAtmBlinkColor(const QString& color_one = "black",
                        const QString& color_two = "grey");
  void SetBackgroundImage(
      const QString& background_image = ":/images/north_star_background.jpg");
  void SetBackgroundColor(
      const QString& background_color = "rgb(115, 210, 22)");

 signals:
  void BlinkColor();
  void Exit();

 public slots:
  void AtmBlinkColor();
  void ChangeTimeDate();
  void ShowExitWidget();

 protected:
  void keyPressEvent(QKeyEvent* event);

 private:
  void InitialSettings();
  void SetWidgetAppearance();
  void SetConnections();
  void InitializeObjects();
  void RunTimers();
  void BlockKeys();

  Ui::AtmSplashScreen* ui = nullptr;
  QTimer* color_swap_timer_ = nullptr;
  QTimer* time_date_timer_ = nullptr;
  TextColorSwapper* color_swapper_ = nullptr;
  ExitDialog* exit_dialog_ = nullptr;

  QString blink_color_one_;
  QString blink_color_two_;
};

#endif  // ATM_SPLASH_SCREEN_H
