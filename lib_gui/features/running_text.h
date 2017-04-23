#ifndef RUNNING_TEXT_H
#define RUNNING_TEXT_H

#include <QLabel>

class RunningText : public QLabel {
 public:
  void UpdateText(QLabel* label);
};

#endif  // RUNNING_TEXT_H
