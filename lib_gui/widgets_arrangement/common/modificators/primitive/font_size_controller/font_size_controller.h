#ifndef FONT_SIZE_CONTROLLER_H
#define FONT_SIZE_CONTROLLER_H

#include <QFont>
#include <QFontMetrics>
#include <QLabel>
#include <QPushButton>
#include <QRect>

class QPushButton;
class QLabel;

class FontSizeController {
 public:
  void ControllFontSize(QPushButton* widget);
  void ControllFontSize(QLabel* widget);

 private:
  void GetInitDebugInfo();
  void GetDebugInfo();

  QRect init_widget_geometry_;
  QRect init_font_geometry_;
  QFont init_font_;
  int init_fc_ = 0;

  QRect widget_geometry_;
  QRect font_geometry_;
  QFont font_;
  int fc_ = 0;

  bool is_first_calc_ = true;
};

#endif  // FONT_SIZE_CONTROLLER_H
