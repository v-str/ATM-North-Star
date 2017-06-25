#ifndef APPLICATION_COLOR_H
#define APPLICATION_COLOR_H

#include <QString>

class ApplicationColor {
 public:
  static void SetWidgetColor(const QString main_color,
                             const QString secondary_color,
                             const QString additional_color);

  static QString MainColor();
  static QString SecondaryColor();
  static QString AdditionalColor();

 private:
  static QString main_app_color_;
  static QString secondary_app_color_;
  static QString additional_app_color_;

  static QString splash_screen_blink_color_one_;
  static QString splash_screen_blink_color_two_;
};

#endif  // APPLICATION_COLOR_H
