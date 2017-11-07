#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QFont>
#include <QFontMetrics>
#include <QLabel>
#include <QPushButton>
#include <QRect>

#include <iwcs.h>

class FontSizeController {
 public:
  void ControllFontSize(QPushButton* widget);
  void ControllFontSize(QLabel* widget);

 private:
  void GetInitDebugInfo();
  void GetDebugInfo();

  IWCS iwcs_;

  QRect widget_geometry_;
  QRect font_geometry_;
  QFont font_;
  int fc_ = 0;

  bool is_first_calc_ = true;
};

#endif  // FONT_SIZE_CONTROLLER_H
