#include <font_size_controller.h>

#include <QFont>
#include <QWidget>

void FontSizeController::ControlFontSize(int initial_font_size,
                                         int divide_coefficient_per_scale,
                                         int current_widget_width,
                                         QWidget* widget) {
  int grows_coefficient = current_widget_width / divide_coefficient_per_scale;
  int font_size = initial_font_size + grows_coefficient;

  QFont new_font = widget->font();
  new_font.setPointSize(font_size);

  widget->setFont(new_font);
}
