#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QFont>
#include <QRect>

class QPushButton;

class FontSizeController {
 public:
  void ControllFontSize(QPushButton* widget);

 private:
  QRect widget_geometry_;
  QRect font_geometry_;
};

#endif  // FONT_SIZE_CONTROLLER_H
