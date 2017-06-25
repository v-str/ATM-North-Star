#ifndef WIDGET_COLOR_H
#define WIDGET_COLOR_H

#include <QString>

class WidgetColor {
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
};

#endif  // WIDGET_COLOR_H
