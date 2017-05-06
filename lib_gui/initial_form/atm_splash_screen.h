#ifndef ATM_SPLASH_SCREEN_H
#define ATM_SPLASH_SCREEN_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>

#include "text_color_swapper.h"

namespace Ui {
class AtmSplashScreen;
}

class AtmSplashScreen : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmSplashScreen(QWidget* parent = nullptr);
  ~AtmSplashScreen();

 public slots:
  void ChangeTextColor();
  void ChangeTimeDate();

 protected:
  void keyPressEvent(QKeyEvent* event);

 private:
  void SetMainFormProperties();
  void SetConnections();
  void InitializeObjects();
  void RunTimers();

  Ui::AtmSplashScreen* ui = nullptr;

  QTimer* color_swap_timer_ = nullptr;
  QTimer* time_date_timer_ = nullptr;

  TextColorSwapper* color_swapper_ = nullptr;
};

#endif  // ATM_SPLASH_SCREEN_H
