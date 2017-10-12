#ifndef TIME_LABEL_H
#define TIME_LABEL_H

#include <QLabel>

class QTimer;

class TimeLabel : public QLabel {
  Q_OBJECT
 public:
  TimeLabel(QWidget* parent = nullptr);
  ~TimeLabel();

 public slots:
  void UpdateTime();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetConnection();
  void SetDefaultSettings();

  QTimer* timer_ = nullptr;

  static const int kOneSecond = 1000;
};

#endif  // TIME_LABEL_H
