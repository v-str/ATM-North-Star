#include <atm_button.h>

#include <QFocusEvent>
#include <QString>
#include <QWidget>

AtmButton::AtmButton(QWidget* widget) : QPushButton(widget) {}

AtmButton::AtmButton(const QString& text, QWidget* widget)
    : QPushButton(text, widget) {}

void AtmButton::SetGeometry(const QRect& geometry) {
  setGeometry(geometry);
  geometry_ = geometry;
}

AtmButton::~AtmButton() {}

void AtmButton::focusInEvent(QFocusEvent*) {}

void AtmButton::focusOutEvent(QFocusEvent*) {}
