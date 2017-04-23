#include "text_color_swapper.h"

void TextColorSwapper::ChangeColor(QLabel* label,
                                   const QString& first_color,
                                   const QString& second_color) {
  QString stylesheet =
      "QLabel{"
      "border: 0px solid black;"
      "color: %1;"
      "}";

  if (state_) {
    label->setStyleSheet(stylesheet.arg(first_color));
    state_ = false;
  } else {
    label->setStyleSheet(stylesheet.arg(second_color));
    state_ = true;
  }
}
