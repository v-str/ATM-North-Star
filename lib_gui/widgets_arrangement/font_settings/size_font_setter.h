#ifndef SIZE_FONT_SETTER_H
#define SIZE_FONT_SETTER_H

class SizeFontSetter {
 public:
  void SetScaleCoefficient(int scale_coefficient);
  void SetFontSizeGain(int font_size_gain);

 private:
  int scale_coefficient_ = 0;
  int font_size_gain_ = 1;
};

#endif  // SIZE_FONT_SETTER_H
