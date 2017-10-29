#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QRect>

class QWidget;

class FontSizeController {
 public:
  void SetDefaultParameters(const QWidget& widget);

 private:
  int default_widget_height_;
  int default_font_size_px_ = 0;
};

#endif  // FONT_SIZE_CONTROLLER_H
