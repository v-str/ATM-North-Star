#ifndef WIDGET_COLOR_H
#define WIDGET_COLOR_H

#include <QString>

struct WidgetColor {
  WidgetColor(const QString& main_color = "yellow",
              const QString& secondary_color = "red",
              const QString& additional_color = "blue")
      : main_color_(main_color),
        secondary_color_(secondary_color),
        additional_color_(additional_color) {}

  QString main_color_;
  QString secondary_color_;
  QString additional_color_;
};

#endif  // WIDGET_COLOR_H
