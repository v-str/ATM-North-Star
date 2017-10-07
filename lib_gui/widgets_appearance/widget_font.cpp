#include <widget_font.h>

WidgetFont::WidgetFont(int font_size_pt) {
  win32_font_.setPointSize(font_size_pt);
  linux_font_.setPointSize(font_size_pt);

  win32_font_.setFamily("MS PGothic");
  linux_font_.setFamily("Ubuntu");
}

QFont WidgetFont::GetFont() const {
#ifdef WIN32
  return win32_font_;
#else
  return linux_font_;
#endif
}
