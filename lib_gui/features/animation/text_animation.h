#ifndef TEXT_ANIMATION_H
#define TEXT_ANIMATION_H

#include <QString>

class QLabel;
class QTimer;
class QWidget;

class TextAnimation {
 public:
  void RunningTextStrip(QLabel* label);
  void WriteTextWithDelay(const QString& text, int delay_msec, QLabel* widget);

 private:
};

#endif  // TEXT_ANIMATION_H
