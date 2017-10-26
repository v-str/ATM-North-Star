#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

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

  double side_ratio_;
  int font_size_;
};

#endif  // FONT_SIZE_CONTROLLER_H
