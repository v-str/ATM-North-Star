#include <font_size_controller.h>

#include <QFontMetrics>
#include <QLabel>
#include <QPushButton>

void FontSizeController::SetnitialMeasurements(QWidget* widget,
                                               double font_scale_multiplier) {
  iwcs_.SetIww(widget->geometry().width());
  iwcs_.SetIwh(widget->geometry().height());
  iwcs_.SetIfps(widget->font().pixelSize());
  font_scale_multiplier_ = font_scale_multiplier;
  font_ = widget->font();
}

void FontSizeController::ControllFontSize(QWidget* widget) {
  widget_geometry_ = widget->geometry();
  font_ = widget->font();

  if (IsSidesSizeEqualDefault()) {
    font_.setPixelSize(iwcs_.Ifps());
    widget->setFont(font_);
  }

  if (IsSidesSizeChanged()) {
    int delta_width = widget_geometry_.width() - iwcs_.Iww();
    int delta_height = widget_geometry_.height() - iwcs_.Iwh();
    if (delta_width >= delta_height) {
      width_font_increment_ =
          font_scale_multiplier_ * (delta_height / iwcs_.Ifps());
      font_.setPixelSize(iwcs_.Ifps() + width_font_increment_);
      widget->setFont(font_);
    } else {
      height_font_increment_ =
          font_scale_multiplier_ * (delta_width / iwcs_.Ifps());
      font_.setPixelSize(iwcs_.Ifps() + height_font_increment_);
      widget->setFont(font_);
    }
  }
}

QFont FontSizeController::CurrentFont() const { return font_; }

bool FontSizeController::IsSidesSizeEqualDefault() const {
  return widget_geometry_.width() == iwcs_.Iww() ||
         widget_geometry_.height() == iwcs_.Iwh();
}

bool FontSizeController::IsSidesSizeChanged() const {
  return widget_geometry_.width() != iwcs_.Iww() &&
         widget_geometry_.height() != iwcs_.Iwh();
}
