#ifndef TIME_LABEL_H
#define TIME_LABEL_H

#include <QLabel>
#include <QWidget>

class QWidget;

class TimeLabel : public QLabel {
 public:
  TimeLabel(QWidget* widget = nullptr);
  ~TimeLabel();

 private:
};

#endif  // TIME_LABEL_H
