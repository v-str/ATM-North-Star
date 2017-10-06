#ifndef DATE_LABEL_H
#define DATE_LABEL_H

#include <QLabel>

class QTimer;

class DateLabel : public QLabel {
  Q_OBJECT
 public:
  DateLabel(QLabel* parent = nullptr);
  ~DateLabel();

 private:
  QTimer* timer_ = nullptr;
};

#endif  // DATE_LABEL_H
