#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QFont>
#include <QFontMetrics>
#include <QRect>

class QWidget;

class FontSizeController {
 public:
  void ControllFontSize(QWidget* widget);

 private:
  QFont widget_font_;
};

#endif  // FONT_SIZE_CONTROLLER_H
