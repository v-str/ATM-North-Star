#ifndef TIME_LABEL_H
#define TIME_LABEL_H

#include <QLabel>

class TimeLabel : public QLabel {
  Q_OBJECT
 public:
  TimeLabel(QLabel* parent = nullptr);
  ~TimeLabel();
};

#endif  // TIME_LABEL_H
