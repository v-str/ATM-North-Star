#ifndef TIME_LABEL_H
#define TIME_LABEL_H

#include <QLabel>

class QTimer;
class GeometryComposer;

class TimeLabel : public QLabel {
  Q_OBJECT
 public:
  TimeLabel(QLabel* parent = nullptr);
  ~TimeLabel();

 public slots:
  void UpdateTime();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetConnection();
  void SetDefaultSettings();

  QTimer* timer_ = nullptr;
  GeometryComposer* composer_ = nullptr;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;

  static const int kOneSecond = 1000;
};

#endif  // TIME_LABEL_H
