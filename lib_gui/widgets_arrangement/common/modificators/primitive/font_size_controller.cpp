#include <font_size_controller.h>

#include <QFont>
#include <QWidget>

#include <QDebug>

void FontSizeController::SetDefaultParameters(int height,
                                              int font_size_px,
                                              int font_size_limit_px) {
  default_widget_height_ = height;
  default_font_size_px_ = font_size_px;
  font_size_limit_px_ = font_size_limit_px;

  increment_factor_ =
      double(default_widget_height_) / double(default_font_size_px_);
}

void FontSizeController::ControllFontSize(int current_height, QWidget* widget) {
  QFont widget_font = widget->font();
  if (current_height != default_widget_height_) {
    int new_font_size_px = double(current_height) / increment_factor_;

    if (new_font_size_px > font_size_limit_px_) {
      new_font_size_px = font_size_limit_px_;
    }

    widget_font.setPixelSize(new_font_size_px);
    widget->setFont(widget_font);
  }

  qDebug() << "Font: " << widget_font.pixelSize();
}
