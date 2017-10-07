#include <widget_font.h>

QString WidgetFont::kWin32Family = "MS PGothic";
QString WidgetFont::kLinuxFamily = "Ubuntu";

QFont WidgetFont::kWin32Font;
QFont WidgetFont::kLinuxFont;

WidgetFont::WidgetFont() { SetFamily(); }

QFont WidgetFont::GetFont(int font_point_size_pt) {
#ifdef WIN32
  kWin32Font.setPixelSize(font_point_size_pt);
  return kWin32Font;
#else
  linux_font_.setPointSize(font_point_size_pt);
  return linux_font_;
#endif
}

void WidgetFont::SetFamily() {
  kWin32Font.setFamily(kWin32Family);
  kLinuxFont.setFamily(kLinuxFamily);
}
