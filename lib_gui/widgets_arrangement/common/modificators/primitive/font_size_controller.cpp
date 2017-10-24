#include <font_size_controller.h>

#include <QFont>
#include <QWidget>

double FontSizeController::kSideRatio = 0.0;

void FontSizeController::ControlFontSize(int initial_font_size,
                                         int font_scale_coefficient,
                                         int current_widget_width,
                                         QWidget* widget) {
  CalculateSideRatio(widget->width(), widget->height());

  int grows_coefficient = current_widget_width / font_scale_coefficient;
  int font_size = initial_font_size + grows_coefficient;

  QFont new_font = widget->font();
  new_font.setPointSize(font_size);

  widget->setFont(new_font);
}

void FontSizeController::CalculateSideRatio(int widget_width,
                                            int widget_height) {
  kSideRatio = double(widget_width) / double(widget_height);
}
