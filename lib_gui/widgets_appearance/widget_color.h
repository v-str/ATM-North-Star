#ifndef WIDGET_COLOR_H
#define WIDGET_COLOR_H

#include <QString>

class WidgetColor {
 public:
  WidgetColor(const QString& main_color = "yellow",
              const QString& secondary_color = "red",
              const QString& additional_color = "blue");

  QString MainColor() const;
  QString SecondaryColor() const;
  QString AdditionalColor() const;

 private:
  QString main_color_;
  QString secondary_color_;
  QString additional_color_;
};

#endif  // WIDGET_COLOR_H
