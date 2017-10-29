#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QFont>
#include <QRect>

class QWidget;

class FontSizeController {
 public:
  void SetDefaultParameters(int design_height,
                            int font_size_px,
                            int font_size_limit_px);
  void ControllFontSize(int current_height, QWidget* widget);

 private:
  void ChangeFontSize(int current_height);
  bool IsFontSizeAcceptable();

  QFont widget_font_;

  int design_height_ = 0;
  int font_size_px_ = 0;
  int font_size_limit_px_ = 0;

  double increment_factor_;
};

#endif  // FONT_SIZE_CONTROLLER_H
