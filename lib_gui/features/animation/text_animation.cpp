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
