#ifndef DATE_LABEL_H
#define DATE_LABEL_H

#include <QLabel>

class DateLabel : public QLabel {
  Q_OBJECT
 public:
  DateLabel(QLabel* parent = nullptr);
  ~DateLabel();
};

#endif  // DATE_LABEL_H
