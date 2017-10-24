#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

class QWidget;

class FontSizeController {
 public:
  static void ControlFontSize(int initial_font_size,
                              int font_scale_coefficient,
                              int current_widget_width,
                              QWidget* widget);

 private:
  static void CalculateSideRatio(int widget_width, int widget_height);

  static double kSideRatio;
};

#endif  // FONT_SIZE_CONTROLLER_H
