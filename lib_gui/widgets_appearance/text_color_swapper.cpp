#include <text_color_swapper.h>

#include <application_color.h>

TextColorSwapper::TextColorSwapper()
    : swap_color_one_(ApplicationColor::BlinkColorOne()),
      swap_color_two_(ApplicationColor::BlinkColorTwo()) {}

void TextColorSwapper::SwapColors(QLabel* label) {
  QString stylesheet =
      "QLabel{"
      "border: 0px solid black;"
      "color: %1;"
      "}";

  if (swap_state_) {
    label->setStyleSheet(stylesheet.arg(swap_color_one_));
    swap_state_ = false;
  } else {
    label->setStyleSheet(stylesheet.arg(swap_color_two_));
    swap_state_ = true;
  }
}
