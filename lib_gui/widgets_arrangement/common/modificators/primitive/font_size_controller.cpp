#include <font_size_controller.h>

#include <QWidget>

FontSizeController::FontSizeController() : side_ratio_(2.0), font_size_(11) {}

void FontSizeController::ControlFontSize(int initial_font_size,
                                         int ratio_limit,
                                         int font_scale_coefficient,
                                         QWidget* widget) {
  CalculateSideRatio(widget->width(), widget->height());

  if (side_ratio_ < ratio_limit) {
    int grows_coefficient = widget->width() / font_scale_coefficient;
    font_size_ = initial_font_size + grows_coefficient;
  }

  calculated_font_ = widget->font();
  calculated_font_.setPointSize(font_size_);

  widget->setFont(calculated_font_);
}

void FontSizeController::CalculateSideRatio(int widget_width,
                                            int widget_height) {
  side_ratio_ = double(widget_width) / double(widget_height);
}
