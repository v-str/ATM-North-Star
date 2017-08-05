#include <atm_button.h>

#include <QEvent>
#include <QFont>
#include <QResizeEvent>
#include <QSize>
#include <QSizePolicy>
#include <QString>
#include <QWidget>

#include <font_size_controller.h>

AtmButton::AtmButton(const QString& text, QWidget* widget)
    : QPushButton(text, widget), font_size_controller_(new FontSizeController) {
  offset_side_ = kRight;

  SetSizePolicy();
}

void AtmButton::SetOffsetSide(unsigned int offset_side) {
  offset_side_ = offset_side;
}

void AtmButton::SetXHoverOffset(int x_offset) { x_offset_ = x_offset; }

void AtmButton::SetYHoverOffset(int y_offset) { y_offset_ = y_offset; }

AtmButton::~AtmButton() { delete font_size_controller_; }

void AtmButton::enterEvent(QEvent*) { OffsetButton(); }

void AtmButton::leaveEvent(QEvent*) { ReturnToInitialPosition(); }

void AtmButton::resizeEvent(QResizeEvent* event) {
  font_size_controller_->ControlFontSize(event->size().width(), this);
}

void AtmButton::SetSizePolicy() {
  QSizePolicy size_policy = this->sizePolicy();
  size_policy.setVerticalPolicy(QSizePolicy::Expanding);

  setSizePolicy(size_policy);
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
