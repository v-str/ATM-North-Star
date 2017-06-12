#include <splash_screen_resize_composer.h>

void SplashScreenResizeComposer::SetGeometry(const QRect& splash_screen,
                                             const QRect& exit_button,
                                             const QRect& version_label,
                                             const QRect& company_name_label,
                                             const QRect& time_date_label,
                                             const QRect& atm_label,
                                             const QRect& text_label,
                                             const QRect& frame) {
  splash_screen_ = splash_screen;
  exit_button_ = exit_button;
  version_label_ = version_label;
  company_name_label_ = company_name_label;
  time_date_label_ = time_date_label;
  atm_label_ = atm_label;
  text_label_ = text_label;
  frame_ = frame;
}

void SplashScreenResizeComposer::GetExtraWidth(int extra_width) {
  extra_width_ = extra_width;
}

void SplashScreenResizeComposer::GetExtraHeight(int extra_height) {
  extra_height_ = extra_height;
}
