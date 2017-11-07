#include <font_size_controller.h>

#include <QFontMetrics>
#include <QLabel>
#include <QPushButton>

#include <QDebug>

void FontSizeController::TakeInitialMeasurements(QWidget* widget) {
  iwcs_.SetIww(widget->geometry().width());
  iwcs_.SetIwh(widget->geometry().height());
  iwcs_.SetIfps(widget->font().pixelSize());

  GetInitDebugInfo();
}

void FontSizeController::ControllFontSize(QWidget* widget) {
  widget_geometry_ = widget->geometry();
  font_ = widget->font();

  GetInitDebugInfo();
  GetDebugInfo();

  if (widget_geometry_.width() == iwcs_.Iww() ||
      widget_geometry_.height() == iwcs_.Iwh()) {
    font_.setPixelSize(iwcs_.Ifps());
    widget->setFont(font_);

    qDebug() << "\nOne of the sides have initial size.\n"
                "Font size set to initial value = "
             << QString::number(iwcs_.Ifps()) << "pixels";
  }
}

void FontSizeController::GetInitDebugInfo() {
  system("clear");
  qDebug() << "Init widget width: " << QString::number(iwcs_.Iww());
  qDebug() << "Init widget height: " << QString::number(iwcs_.Iwh());
  qDebug() << "Init font pixel size: " << QString::number(iwcs_.Ifps());
  qDebug() << "Init FCh: " << QString::number(iwcs_.Ifch());
  qDebug() << "Init FCw: " << QString::number(iwcs_.Ifcw());
}

void FontSizeController::GetDebugInfo() {
  qDebug() << "\n\nGeometry changed!\n\n";
  qDebug() << "Widget width: " << QString::number(widget_geometry_.width());
  qDebug() << "Widget height: " << QString::number(widget_geometry_.height());
}
