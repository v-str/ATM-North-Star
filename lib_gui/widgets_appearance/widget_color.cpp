#include <widget_color.h>

QString WidgetColor::main_app_color_ = "yellow";
QString WidgetColor::secondary_app_color_ = "red";
QString WidgetColor::additional_app_color_ = "blue";

void WidgetColor::SetWidgetColor(const QString main_color,
                                 const QString secondary_color,
                                 const QString additional_color) {
  main_app_color_ = main_color;
  secondary_app_color_ = secondary_color;
  additional_app_color_ = additional_color;
}

QString WidgetColor::MainColor() { return main_app_color_; }

QString WidgetColor::SecondaryColor() { return secondary_app_color_; }

QString WidgetColor::AdditionalColor() { return additional_app_color_; }
