#ifndef TEXT_COLOR_SWAPPER_H
#define TEXT_COLOR_SWAPPER_H

#include <QLabel>
#include <QString>

class TextColorSwapper {
 public:
  void ChangeColor(QLabel* label,
                   const QString& first_color,
                   const QString& second_color);

 private:
  bool state_ = true;
};

#endif  // TEXT_COLOR_SWAPPER_H
