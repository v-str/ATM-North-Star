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

  font_height_ = font_metrics.height();

  GetDebugInfo();
}

void FontSizeController::GetDebugInfo() {
  WriteWidgetSizes();
  WriteWidgetFontInfo();
  WriteHeightCoefficient();
}

void FontSizeController::WriteWidgetSizes() {
  qDebug() << "Widget height: " << QString::number(widget_geometry_.height());
  qDebug() << "Widget width: " << QString::number(widget_geometry_.width());
}

void FontSizeController::WriteWidgetFontInfo() {
  qDebug() << "Widget font height: " << QString::number(font_height_);
}

void FontSizeController::WriteHeightCoefficient() {
  double height_coefficient =
      double(widget_geometry_.height()) / double(font_height_);
  if (is_first_coefficient_calculation_) {
    qDebug() << "Initial coeffiient: " << QString::number(height_coefficient)
             << "\n\n";
    is_first_coefficient_calculation_ = false;
  } else {
    qDebug() << "Height coefficient: " << QString::number(height_coefficient)
             << "\n\n";
  }
}
