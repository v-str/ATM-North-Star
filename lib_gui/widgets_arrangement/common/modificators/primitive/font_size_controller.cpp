#include <font_size_controller.h>

#include <QWidget>

void FontSizeController::SetDefaultParameters(int design_height,
                                              int font_size_px,
                                              int font_size_limit_px) {
  design_height_ = design_height;
  font_size_px_ = font_size_px;
  font_size_limit_px_ = font_size_limit_px;

  increment_factor_ = double(design_height_) / double(font_size_px_);
}

void FontSizeController::ControllFontSize(int current_height, QWidget* widget) {
  if (current_height > design_height_) {
    ChangeFontSize(current_height);
    widget_font_ = widget->font();
    widget_font_.setPixelSize(font_size_px_);
    widget->setFont(widget_font_);
  }
}

void FontSizeController::ChangeFontSize(int current_height) {
  font_size_px_ = double(current_height) / increment_factor_;

  if (!IsFontSizeAcceptable()) {
    font_size_px_ = font_size_limit_px_;
  }
}

bool FontSizeController::IsFontSizeAcceptable() {
  return font_size_px_ < font_size_limit_px_;
}
