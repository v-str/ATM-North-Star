#include <font_size_controller.h>

#include <QFont>
#include <QWidget>

FontSizeController::FontSizeController() : side_ratio_(2.0), font_size_(11) {}

void FontSizeController::ControlFontSize(int initial_font_size,
                                         int ratio_limit,
                                         int font_scale_coefficient,
                                         int current_widget_width,
                                         QWidget* widget) {
  CalculateSideRatio(widget->width(), widget->height());

  if (side_ratio_ < ratio_limit) {
    int grows_coefficient = current_widget_width / font_scale_coefficient;
    font_size_ = initial_font_size + grows_coefficient;
  }

  QFont new_font = widget->font();
  new_font.setPointSize(font_size_);

  widget->setFont(new_font);
}

void FontSizeController::CalculateSideRatio(int widget_width,
                                            int widget_height) {
  side_ratio_ = double(widget_width) / double(widget_height);
}
