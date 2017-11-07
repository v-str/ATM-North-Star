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
  void TakeInitialMeasurements(QWidget* widget);

  void ControllFontSize(QWidget* widget);

 private:
  bool IsSidesSizeEqualDefault() const;
  bool IsSidesSizeChanged() const;

  void GetInitDebugInfo();
  void GetDebugInfo();

  IWCS iwcs_;

  QRect widget_geometry_;
  QFont font_;
};

#endif  // FONT_SIZE_CONTROLLER_H
