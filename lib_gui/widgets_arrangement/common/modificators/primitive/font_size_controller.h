#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QFont>

class QWidget;

class FontSizeController {
 public:
  FontSizeController();

  void ControlFontSize(int initial_font_size,
                       int ratio_limit,
                       int font_scale_coefficient,
                       QWidget* widget);

 private:
  void CalculateSideRatio(int widget_width, int widget_height);

  QFont calculated_font_;

  double side_ratio_;
  int font_size_;
};

#endif  // FONT_SIZE_CONTROLLER_H
