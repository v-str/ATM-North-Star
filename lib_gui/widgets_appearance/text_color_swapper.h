#ifndef TEXT_COLOR_SWAPPER_H
#define TEXT_COLOR_SWAPPER_H

#include <QLabel>
#include <QString>

class TextColorSwapper {
 public:
  TextColorSwapper();

  void SwapColors(QLabel* label);

 private:
  QString swap_color_one_ = "#994C00";
  QString swap_color_two_ = "#CC6600";

  bool swap_state_ = true;
};

#endif  // TEXT_COLOR_SWAPPER_H
