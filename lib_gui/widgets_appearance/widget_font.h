#ifndef WIDGET_FONT_H
#define WIDGET_FONT_H

#include <QFont>
#include <QString>

class WidgetFont {
 public:
  static QFont SetFont(int font_size_px = 10);

 private:
  static void SetFamily();

  static QString kWin32Family;
  static QString kLinuxFamily;

  static QFont kWin32Font;
  static QFont kLinuxFont;
};

#endif  // WIDGET_FONT_H
