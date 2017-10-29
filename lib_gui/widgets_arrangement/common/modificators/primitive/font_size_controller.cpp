#include <font_size_controller.h>

#include <QFont>
#include <QWidget>

#include <QDebug>

void FontSizeController::SetDefaultParameters(const QWidget& widget) {
  default_widget_height_ = widget.height();
  default_font_size_px_ = widget.font().pixelSize();

  qDebug() << "Height: " << default_widget_height_
           << "\nFont size: " << default_font_size_px_;
}
