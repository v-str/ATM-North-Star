#include <application_color.h>

QString ApplicationColor::main_app_color_ = "yellow";
QString ApplicationColor::secondary_app_color_ = "red";
QString ApplicationColor::additional_app_color_ = "blue";

QString ApplicationColor::splash_screen_blink_color_one_ = "#CCCC00";
QString ApplicationColor::splash_screen_blink_color_two_ = "#999900";

QString ApplicationColor::application_background_color_ = "black";

void ApplicationColor::SetWidgetColor(const QString main_color,
                                      const QString secondary_color,
                                      const QString additional_color) {
  main_app_color_ = main_color;
  secondary_app_color_ = secondary_color;
  additional_app_color_ = additional_color;
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
