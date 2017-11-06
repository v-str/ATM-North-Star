#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QFont>
#include <QRect>

class QPushButton;
class QLabel;

class FontSizeController {
 public:
  void ControllFontSize(QPushButton* widget);
  void ControllFontSize(QLabel* widget);

 private:
  void GetDebugInfo();

  void WriteWidgetSizes();
  void WriteWidgetFontInfo();
  void WriteHeightCoefficient();

  QRect widget_geometry_;
  QRect font_geometry_;

  int font_height_ = 0;

  bool is_first_coefficient_calculation_ = true;
};

#endif  // FONT_SIZE_CONTROLLER_H
