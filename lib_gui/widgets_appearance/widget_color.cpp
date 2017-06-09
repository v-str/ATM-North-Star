#include <widget_color.h>

WidgetColor::WidgetColor(const QString& main_color,
                         const QString& secondary_color,
                         const QString& additional_color)
    : main_color_(main_color),
      secondary_color_(secondary_color),
      additional_color_(additional_color) {}
