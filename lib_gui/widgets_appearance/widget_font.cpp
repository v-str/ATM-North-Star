#include <widget_font.h>

QString WidgetFont::kWin32Family = "Copperplate Gothic Bold";
QString WidgetFont::kLinuxFamily = "Tlwg Mono";

QFont WidgetFont::kWin32Font;
QFont WidgetFont::kLinuxFont;

QFont WidgetFont::SetFont(int font_size_px) {
  SetFamily();
#ifdef WIN32
  kWin32Font.setPixelSize(font_size_px);
  return kWin32Font;
#else
  kLinuxFont.setPixelSize(font_size_px);
  return kLinuxFont;
#endif
}

void WidgetFont::SetFamily() {
  kWin32Font.setFamily(kWin32Family);
  kLinuxFont.setFamily(kLinuxFamily);
}
