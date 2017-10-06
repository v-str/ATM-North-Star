#ifndef TIME_LABEL_H
#define TIME_LABEL_H

#include <QLabel>

class QTimer;

class TimeLabel : public QLabel {
  Q_OBJECT
 public:
  TimeLabel(QLabel* parent = nullptr);
  ~TimeLabel();

 private:
  QTimer* timer_ = nullptr;
};

#endif  // TIME_LABEL_H
