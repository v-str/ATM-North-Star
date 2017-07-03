#include <atm_button.h>

#include <QFocusEvent>
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
