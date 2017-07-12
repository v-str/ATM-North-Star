#include <atm_button.h>

#include <QEvent>
#include <QFont>
#include <QResizeEvent>
#include <QSize>
#include <QString>
#include <QWidget>

AtmButton::AtmButton(QWidget* widget) : QPushButton(widget) {}

AtmButton::AtmButton(const QString& text,
                     unsigned int offset_side,
                     QWidget* widget)
    : QPushButton(text, widget), offset_side_(offset_side) {
  QFont initial_font = font();
}

void AtmButton::SetOffsetSide(unsigned int offset_side) {
  offset_side_ = offset_side;
}

void AtmButton::SetXHoverOffset(int x_offset) { x_offset_ = x_offset; }

void AtmButton::SetYHoverOffset(int y_offset) { y_offset_ = y_offset; }

void AtmButton::SetDivideCoefficient(unsigned int divide_coefficient) {
  divide_coefficient_ = divide_coefficient;
}

AtmButton::~AtmButton() {}

void AtmButton::enterEvent(QEvent*) { OffsetButton(); }

void AtmButton::leaveEvent(QEvent*) { ReturnToInitialPosition(); }

void AtmButton::resizeEvent(QResizeEvent* event) {
  grows_coefficient_ = event->size().width() / divide_coefficient_;

  int font_size = kInitialFontSize + grows_coefficient_;

  QFont new_font = font();
  new_font.setPointSize(font_size);

  setFont(new_font);
}

void AtmButton::OffsetButton() {
  int x_pos = x();
  int y_pos = y();

  if (offset_side_ & kLeft) {
    x_pos -= x_offset_;
  }
  if (offset_side_ & kRight) {
    x_pos += x_offset_;
  }
  if (offset_side_ & kUp) {
    y_pos -= y_offset_;
  }
  if (offset_side_ & kDown) {
    y_pos += y_offset_;
  }
  if (offset_side_ & kNone) {
    x_pos = x();
    y_pos = y();
  }

  move(x_pos, y_pos);
}

void AtmButton::ReturnToInitialPosition() {
  int x_pos = x();
  int y_pos = y();

  if (offset_side_ & kLeft) {
    x_pos += x_offset_;
  }
  if (offset_side_ & kRight) {
    x_pos -= x_offset_;
  }
  if (offset_side_ & kUp) {
    y_pos += y_offset_;
  }
  if (offset_side_ & kDown) {
    y_pos -= y_offset_;
  }

  move(x_pos, y_pos);
}
