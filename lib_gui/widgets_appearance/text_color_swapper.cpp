#include "text_color_swapper.h"

void TextColorSwapper::SwapColors(QLabel* label,
                                  const QString& first_color,
                                  const QString& second_color) {
  QString stylesheet =
      "QLabel{"
      "border: 0px solid black;"
      "color: %1;"
      "}";

  if (swap_state_) {
    label->setStyleSheet(stylesheet.arg(first_color));
    swap_state_ = false;
  } else {
    label->setStyleSheet(stylesheet.arg(second_color));
    swap_state_ = true;
  }
}

void TextColorSwapper::SetSwapColors(const QString& swap_color_one,
                                     const QString& swap_color_two) {
  swap_color_one_ = swap_color_one;
  swap_color_two_ = swap_color_two;
}

QString TextColorSwapper::SwapColorOne() const { return swap_color_one_; }

QString TextColorSwapper::SwapColorTwo() const { return swap_color_two_; }
