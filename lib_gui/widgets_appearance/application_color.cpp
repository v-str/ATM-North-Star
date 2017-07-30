#include <application_color.h>

QString ApplicationColor::main_app_color_ = "#00FFFF";
QString ApplicationColor::secondary_app_color_ = "#66FFFF";
QString ApplicationColor::additional_app_color_ = "#006666";

QString ApplicationColor::splash_screen_blink_color_one_ = "#00FFFF";
QString ApplicationColor::splash_screen_blink_color_two_ = "#009999";

QString ApplicationColor::application_background_color_ = "black";

QString ApplicationColor::checked_background_color_ = "#000000";

void ApplicationColor::SetWidgetColor(const QString main_color,
                                      const QString secondary_color,
                                      const QString additional_color) {
  main_app_color_ = main_color;
  secondary_app_color_ = secondary_color;
  additional_app_color_ = additional_color;
}

void ApplicationColor::SetMainColor(const QString& main_color) {
  main_app_color_ = main_color;
}

void ApplicationColor::SetSecondaryColor(const QString& secondary_color) {
  secondary_app_color_ = secondary_color;
}

void ApplicationColor::SetAdditionalColor(const QString& additional_color) {
  additional_app_color_ = additional_color;
}

void ApplicationColor::SetSplashScreenBlinkColor(const QString& color_one,
                                                 const QString& color_two) {
  splash_screen_blink_color_one_ = color_one;
  splash_screen_blink_color_two_ = color_two;
}

void ApplicationColor::SetBackgroundColor(const QString& background_color) {
  application_background_color_ = background_color;
}

void ApplicationColor::SetCheckedBackgroundColor(
    const QString& background_color) {
  checked_background_color_ = background_color;
}

QString ApplicationColor::MainColor() { return main_app_color_; }

QString ApplicationColor::SecondaryColor() { return secondary_app_color_; }

QString ApplicationColor::AdditionalColor() { return additional_app_color_; }

QString ApplicationColor::BlinkColorOne() {
  return splash_screen_blink_color_one_;
}

QString ApplicationColor::BlinkColorTwo() {
  return splash_screen_blink_color_two_;
}

QString ApplicationColor::ApplicationBackgroundColor() {
  return application_background_color_;
}

QString ApplicationColor::CheckedBackgroundColor() {
  return checked_background_color_;
}
