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
    : QPushButton(text, widget) {}

AtmButton::~AtmButton() {}

void AtmButton::focusInEvent(QFocusEvent*) { move(x() + x_offset_, y()); }

void AtmButton::focusOutEvent(QFocusEvent*) { move(x() - x_offset_, y()); }

void AtmButton::enterEvent(QEvent*) { move(x() + x_offset_, y()); }

void AtmButton::leaveEvent(QEvent*) { move(x() - x_offset_, y()); }
