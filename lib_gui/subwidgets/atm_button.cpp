#include <atm_button.h>

#include <QEvent>
#include <QFocusEvent>
#include <QHoverEvent>
#include <QRect>
#include <QString>
#include <QWidget>

#include <QDebug>

AtmButton::AtmButton(QWidget* widget) : QPushButton(widget) {}

AtmButton::AtmButton(const QString& text, QWidget* widget)
    : QPushButton(text, widget) {
  connect(this, SIGNAL(Hovered()), SLOT(MakeOffset()));
}

AtmButton::~AtmButton() {}

void AtmButton::MakeOffset() { move(x() + x_offset_, y()); }

void AtmButton::focusInEvent(QFocusEvent*) { move(x() + x_offset_, y()); }

void AtmButton::focusOutEvent(QFocusEvent*) { move(x() - x_offset_, y()); }

// void AtmButton::HoverEnter(QHoverEvent*) { /*move(x() + x_offset_, y());*/
//  qDebug() << "OFFSET COMPLETE";
//}

// void AtmButton::HoverLeave(QHoverEvent*) { move(x() - x_offset_, y()); }

// bool AtmButton::event(QEvent* e) {}

void AtmButton::enterEvent(QEvent*) { move(x() + x_offset_, y()); }

void AtmButton::leaveEvent(QEvent*) { move(x() - x_offset_, y()); }
