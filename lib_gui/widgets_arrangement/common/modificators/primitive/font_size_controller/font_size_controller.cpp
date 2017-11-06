#include <font_size_controller.h>

#include <QFontMetrics>
#include <QLabel>
#include <QPushButton>

#include <QDebug>

void FontSizeController::ControllFontSize(QPushButton* widget) {
  QFontMetrics font_metrics(widget->font());
  init_font_geometry_ = font_metrics.boundingRect(widget->text());

  GetInitDebugInfo();
}

void FontSizeController::ControllFontSize(QLabel* widget) {
  QFontMetrics font_metrics(widget->font());
  if (is_first_calc_) {
    init_font_geometry_ = font_metrics.boundingRect(widget->text());
    init_font_ = widget->font();
    init_widget_geometry_ = widget->geometry();
    init_fc_ = init_widget_geometry_.height() / init_font_.pixelSize();
    GetInitDebugInfo();
    is_first_calc_ = false;
  } else {
    widget_geometry_ = widget->geometry();
    GetInitDebugInfo();
    GetDebugInfo();
  }
}

void FontSizeController::GetInitDebugInfo() {
  system("clear");
  qDebug() << "Init widget width: "
           << QString::number(init_widget_geometry_.width());
  qDebug() << "Init widget height: "
           << QString::number(init_widget_geometry_.height());
  qDebug() << "Init font height: "
           << QString::number(init_font_geometry_.height());
  qDebug() << "Init font pixel size: "
           << QString::number(init_font_.pixelSize());
  qDebug() << "Init FC: " << QString::number(init_fc_);
}

void FontSizeController::GetDebugInfo() {
  qDebug() << "\n\nGeometry changed!\n\n";
  qDebug() << "Widget width: " << QString::number(widget_geometry_.width());
  qDebug() << "Widget height: " << QString::number(widget_geometry_.height());
}
