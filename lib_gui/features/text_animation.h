#ifndef TEXT_ANIMATION_H
#define TEXT_ANIMATION_H

#include <QString>

class QLabel;
class QTimer;

class TextAnimation {
 public:
  void RunningTextStrip(QLabel* label);
  bool WriteTextWithDelay(QLabel* label, QTimer* timer, int delay_msec);

 private:
  QString string_buffer_ = "";
  QString new_label_text_ = "";
  int number_of_characters_ = 0;
  int count_ = 0;
  bool is_readable_ = true;
};

#endif  // TEXT_ANIMATION_H
