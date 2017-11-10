#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QFont>
#include <QFontMetrics>
#include <QLabel>
#include <QPushButton>
#include <QRect>
#include <QString>

#include <iwcs.h>

class FontSizeController {
 public:
  void SetnitialMeasurements(QWidget* widget, double font_scale_multiplier);
  void ControllFontSize(QWidget* widget);

  QFont CurrentFont() const;

 private:
  bool IsSidesSizeEqualDefault() const;
  bool IsSidesSizeChanged() const;

  IWCS iwcs_;

  QRect widget_geometry_;
  QFont font_;

  int width_font_increment_ = 0;
  int height_font_increment_ = 0;

  double font_scale_multiplier_;
};

#endif  // FONT_SIZE_CONTROLLER_H
