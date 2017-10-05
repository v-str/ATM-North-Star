#ifndef BASE_ATM_WIDGET_H
#define BASE_ATM_WIDGET_H

#include <QMainWindow>

class QLabel;

class BaseAtmWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit BaseAtmWidget(QWidget* parent = nullptr);
  ~BaseAtmWidget();

 public slots:
  void ChangeTime(QLabel* time_label);
  void ChangeDate(QLabel* date_label);
};

#endif  // BASE_ATM_WIDGET_H
