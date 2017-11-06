#include <font_size_controller.h>

#include <QFontMetrics>
#include <QLabel>
#include <QPushButton>

#include <QDebug>

void FontSizeController::ControllFontSize(QPushButton* widget) {
  QFontMetrics font_metrics(widget->font());

  widget_geometry_ = widget->geometry();
  font_geometry_ = font_metrics.boundingRect(widget->text());

  GetDebugInfo();
}

void FontSizeController::ControllFontSize(QLabel* widget) {
  QFontMetrics font_metrics(widget->font());

  widget_geometry_ = widget->geometry();
  font_geometry_ = font_metrics.boundingRect(widget->text());

  GetDebugInfo();
}

void FontSizeController::GetDebugInfo() {
  qDebug() << "Widget geometry:\nx: " << QString::number(widget_geometry_.x())
           << "\ny: " << QString::number(widget_geometry_.y())
           << "\nwidth: " << QString::number(widget_geometry_.width())
           << "\nheight: " << QString::number(widget_geometry_.x()) << "\n\n";

  qDebug() << "Widget Font geometry:\nx: "
           << QString::number(font_geometry_.x())
           << "\ny: " << QString::number(font_geometry_.y())
           << "\nwidth: " << QString::number(font_geometry_.width())
           << "\nheight: " << QString::number(font_geometry_.height())
           << "\n\n";
}
