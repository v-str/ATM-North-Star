#ifndef DATE_LABEL_H
#define DATE_LABEL_H

#include <QLabel>

class QTimer;

class DateLabel : public QLabel {
  Q_OBJECT
 public:
  DateLabel(QWidget* parent = nullptr);
  ~DateLabel();

 public slots:
  void UpdateTime();

 private:
  QTimer* timer_ = nullptr;

  static const int kOneSecond = 1000;
};

#endif  // DATE_LABEL_H
