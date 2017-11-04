#include <font_size_controller.h>

#include <QFontMetrics>
#include <QPushButton>
#include <QWidget>

#include <QDebug>

void FontSizeController::ControllFontSize(QPushButton* widget) {
  QFontMetrics font_metrics(widget->font());

  widget_geometry_ = widget->geometry();
  font_geometry_ = font_metrics.boundingRect(widget->text());

  qDebug() << "Button geometry:\n"
              "x: "
           << QString::number(widget_geometry_.x()) << "\n"
           << "y: " << QString::number(widget_geometry_.y()) << "\n"
           << "width: " << QString::number(widget_geometry_.width()) << "\n"
           << "height: " << QString::number(widget_geometry_.x()) << "\n\n";

  qDebug() << "Font geometry:\n"
              "x: "
           << QString::number(font_geometry_.x()) << "\n"
           << "y: " << QString::number(font_geometry_.y()) << "\n"
           << "width: " << QString::number(font_geometry_.width()) << "\n"
           << "height: " << QString::number(font_geometry_.height()) << "\n\n";
}
