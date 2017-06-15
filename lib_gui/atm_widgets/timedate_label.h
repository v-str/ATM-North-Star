#ifndef TIMEDATE_LABEL_H
#define TIMEDATE_LABEL_H

#include <QLabel>

class TimeDateLabel : public QLabel {
  Q_OBJECT
 public:
  explicit TimeDateLabel(QWidget* parent = nullptr);
  ~TimeDateLabel();
};

#endif  // TIMEDATE_LABEL_H
