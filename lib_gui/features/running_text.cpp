#include "running_text.h"

#include <QString>

void RunningText::UpdateText(QLabel* label) {
  QString running_text = label->text();

  QString temp_text;

  temp_text = running_text[0];
  running_text.remove(0, 1);
  running_text.push_back(temp_text);

  label->setText(running_text);
}
