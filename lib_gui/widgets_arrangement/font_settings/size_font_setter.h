#ifndef SIZE_FONT_SETTER_H
#define SIZE_FONT_SETTER_H

#include <QFont>

class SizeFontSetter {
 public:
  SizeFontSetter(int scale_coefficient, int font_size_gain);

  void SetScaleCoefficient(int scale_coefficient);
  void SetFontSizeGain(int font_size_gain);

 private:
  QFont widget_font_;

  int scale_coefficient_ = 0;
  int font_size_gain_ = 1;
};

#endif  // SIZE_FONT_SETTER_H
