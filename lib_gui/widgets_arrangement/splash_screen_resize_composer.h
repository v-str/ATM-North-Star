#ifndef SPLASH_SCREEN_RESIZE_COMPOSER_H
#define SPLASH_SCREEN_RESIZE_COMPOSER_H

#include <QRect>

class QPushButton;
class QLabel;
class QFrame;

class SplashScreenResizeComposer {
 public:
  void SetGeometry(const QRect& splash_screen,
                   const QRect& exit_button,
                   const QRect& version_label,
                   const QRect& company_name_label,
                   const QRect& time_date_label,
                   const QRect& atm_label,
                   const QRect& text_label,
                   const QRect& frame);

  void ResizeFrame(QFrame* frame);
  void ResizeExitButton(QPushButton* exit_button);
  void ResizeMinimizeButton(QPushButton* minimize_button);

  void SetExtraWidth(int extra_width);
  void SetExtraHeight(int extra_height);

 private:
  void ComputeExtraButtonParameters();

  QRect splash_screen_;
  QRect exit_button_;
  QRect version_label_;
  QRect company_name_label_;
  QRect time_date_label_;
  QRect atm_label_;
  QRect text_label_;
  QRect frame_;

  int extra_width_ = 0;
  int extra_height_ = 0;

  int extra_button_width_ = 0;
  int extra_button_height_ = 0;
};

#endif  // SPLASH_SCREEN_RESIZE_COMPOSER_H
