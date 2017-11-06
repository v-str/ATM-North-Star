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

  QRect widget_geometry_;
  QRect font_geometry_;
};

#endif  // FONT_SIZE_CONTROLLER_H
