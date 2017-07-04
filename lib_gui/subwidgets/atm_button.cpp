#include <atm_button.h>

#include <QEvent>
#include <QString>
#include <QWidget>

AtmButton::AtmButton(QWidget* widget) : QPushButton(widget) {}

AtmButton::AtmButton(const QString& text, QWidget* widget)
    : QPushButton(text, widget) {}

AtmButton::~AtmButton() {}

void AtmButton::enterEvent(QEvent*) { OffsetButton(); }

void AtmButton::leaveEvent(QEvent*) { ReturnToInitialPosition(); }

void AtmButton::OffsetButton() {
  if (!is_focus_) {
    move(x() + x_offset_, y());
    is_focus_ = true;
  }
}

void AtmButton::ReturnToInitialPosition() {
  if (is_focus_) {
    move(x() - x_offset_, y());
    is_focus_ = false;
  }
}
