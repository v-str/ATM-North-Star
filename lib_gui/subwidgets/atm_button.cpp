#include <atm_button.h>

#include <QEvent>
#include <QString>
#include <QWidget>

AtmButton::AtmButton(QWidget* widget) : QPushButton(widget) {}

AtmButton::AtmButton(const QString& text,
                     unsigned int offset_side,
                     QWidget* widget)
    : QPushButton(text, widget), offset_side_(offset_side) {}

AtmButton::~AtmButton() {}

void AtmButton::enterEvent(QEvent*) { OffsetButton(); }

void AtmButton::leaveEvent(QEvent*) { ReturnToInitialPosition(); }

void AtmButton::OffsetButton() {
  int x_pos = x();
  int y_pos = y();

  if (offset_side_ & kLeft) {
    x_pos -= offset_;
  }
  if (offset_side_ & kRight) {
    x_pos += offset_;
  }
  if (offset_side_ & kUp) {
    y_pos -= offset_;
  }
  if (offset_side_ & kDown) {
    y_pos += offset_;
  }
  move(x_pos, y_pos);
}

void AtmButton::ReturnToInitialPosition() {
  int x_pos = x();
  int y_pos = y();

  if (offset_side_ & kLeft) {
    x_pos += offset_;
  }
  if (offset_side_ & kRight) {
    x_pos -= offset_;
  }
  if (offset_side_ & kUp) {
    y_pos += offset_;
  }
  if (offset_side_ & kDown) {
    y_pos -= offset_;
  }
  move(x_pos, y_pos);
}
