#ifndef TEXT_COLOR_SWAPPER_H
#define TEXT_COLOR_SWAPPER_H

#include <QLabel>
#include <QString>

class TextColorSwapper {
 public:
  void ChangeColor(QLabel* label,
                   const QString& first_color,
                   const QString& second_color);

  void SetSwapColors(const QString& swap_color_one,
                     const QString& swap_color_two);

  QString SwapColorOne() const;
  QString SwapColorTwo() const;

 private:
  QString swap_color_one_ = "#994C00";
  QString swap_color_two_ = "#CC6600";

  bool swap_state_ = true;
};

#endif  // TEXT_COLOR_SWAPPER_H
