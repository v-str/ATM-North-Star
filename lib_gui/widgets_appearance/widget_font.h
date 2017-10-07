#ifndef WIDGET_FONT_H
#define WIDGET_FONT_H

#include <QFont>
#include <QString>

class WidgetFont {
 public:
  WidgetFont(int font_size_pt);

  QFont GetFont() const;

 private:
  QFont win32_font_;
  QFont linux_font_;
};

#endif  // WIDGET_FONT_H
