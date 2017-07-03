#include <atm_button.h>

#include <QWidget>

AtmButton::AtmButton(QWidget* widget) : QPushButton(widget) {}

AtmButton::AtmButton(const QString& text, QWidget* widget)
    : QPushButton(text, widget) {}

AtmButton::~AtmButton() {}
