#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

class QWidget;

class FontSizeController {
 public:
  FontSizeController(int initial_font_size = 10,
                     int divide_coefficient_per_scale = 50);

  void ControlFontSize(int current_widget_width, QWidget* widget);

 private:
  int initial_font_size_ = 0;
  int divide_coefficient_per_scale_ = 0;
};

#endif  // FONT_SIZE_CONTROLLER_H
