#include <font_size_controller.h>

#include <QFont>
#include <QWidget>

FontSizeController::FontSizeController(int initial_font_size,
                                       int divide_coefficient_per_scale)
    : initial_font_size_(initial_font_size),
      divide_coefficient_per_scale_(divide_coefficient_per_scale) {}

void FontSizeController::ControlFontSize(int current_widget_width,
                                         QWidget* widget) {
  int grows_coefficient = current_widget_width / divide_coefficient_per_scale_;
  int font_size = initial_font_size_ + grows_coefficient;

  QFont new_font = widget->font();
  new_font.setPointSize(font_size);

  widget->setFont(new_font);
}
