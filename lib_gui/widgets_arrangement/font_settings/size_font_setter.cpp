#include <size_font_setter.h>

SizeFontSetter::SizeFontSetter(int scale_coefficient, int font_size_gain)
    : scale_coefficient_(scale_coefficient), font_size_gain_(font_size_gain) {}

void SizeFontSetter::SetScaleCoefficient(int scale_coefficient) {
  scale_coefficient_ = scale_coefficient;
}

void SizeFontSetter::SetFontSizeGain(int font_size_gain) {
  font_size_gain_ = font_size_gain;
}
