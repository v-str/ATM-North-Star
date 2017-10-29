#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QRect>

class QWidget;

class FontSizeController {
 public:
  void SetDefaultParameters(int height,
                            int font_size_px,
                            int font_size_limit_px);
  void ControllFontSize(int current_height, QWidget* widget);

 private:
  int default_widget_height_;
  int default_font_size_px_ = 0;
  int font_size_limit_px_ = 0;

  double increment_factor_;
};

#endif  // FONT_SIZE_CONTROLLER_H
