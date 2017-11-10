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
  void SetnitialMeasurements(QWidget* widget);
  void ControllFontSize(QWidget* widget);

  void SetFontScaleMultiplier(int font_scale_multiplier);

  QFont CurrentFont() const;

 private:
  bool IsSidesSizeEqualDefault() const;
  bool IsSidesSizeChanged() const;

  void GetInitDebugInfo();
  void GetDebugInfo();

  IWCS iwcs_;

  QRect widget_geometry_;
  QFont font_;

  int width_font_increment_ = 0;
  int height_font_increment_ = 0;
  int font_scale_multiplier_ = 1;
};

#endif  // FONT_SIZE_CONTROLLER_H
