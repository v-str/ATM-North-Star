#ifndef TIME_LABEL_H
#define TIME_LABEL_H

#include <QLabel>

class QTimer;

class TimeLabel : public QLabel {
  Q_OBJECT
 public:
  TimeLabel(QLabel* parent = nullptr);
  ~TimeLabel();

public slots:
  void UpdateTime();

 private:
  void SetConnection();

  QTimer* timer_ = nullptr;

  static const int kOneSecond = 1000;
};

#endif  // TIME_LABEL_H
