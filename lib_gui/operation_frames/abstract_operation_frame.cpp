#include <abstract_operation_frame.h>

#include <QColor>
#include <QPainter>
#include <QWidget>

#include <application_color.h>
#include <initial_property_installer.h>

AbstractOperationFrame::AbstractOperationFrame(QWidget* parent)
    : QFrame(parent) {
  SetInitialSettings();
}

AbstractOperationFrame::~AbstractOperationFrame() {}

void AbstractOperationFrame::paintEvent(QPaintEvent*) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(QPen(QColor(ApplicationColor::MainColor()), 3));
  painter.drawRoundRect(geometry(), 3, 3);
}

void AbstractOperationFrame::SetInitialSettings() {
  this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}
