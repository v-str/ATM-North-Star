#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

class QWidget;

class FontSizeController {
 public:
  static void ControlFontSize(int initial_font_size,
                              int divide_coefficient_per_scale,
                              int current_widget_width,
                              QWidget* widget);
};

#endif  // FONT_SIZE_CONTROLLER_H
