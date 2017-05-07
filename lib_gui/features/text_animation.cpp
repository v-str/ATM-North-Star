#include "text_animation.h"

#include <QLabel>
#include <QTimer>

void TextAnimation::RunningTextStrip(QLabel* label) {
  QString running_text = label->text();

  QString temp_text;
  temp_text = running_text[0];
  running_text.remove(0, 1);
  running_text.push_back(temp_text);

  label->setText(running_text);
}

bool TextAnimation::WriteTextWithDelay(QLabel* label,
                                       QTimer* timer,
                                       int delay_msec) {
  if (is_readable_) {
    string_buffer_ = label->text();
    is_readable_ = false;
  }

  timer->setInterval(delay_msec);

  number_of_characters_ = string_buffer_.length();
  if (count_ != number_of_characters_) {
    new_label_text_.push_back(string_buffer_[count_]);
    label->setText(new_label_text_);
    count_++;
    return true;
  } else {
    count_ = 0;
    return false;
  }
}
