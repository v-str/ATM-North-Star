#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QObject>

class AtmMainWidget;
class QRect;

class MainWidget : public QObject {
  Q_OBJECT
 public:
  explicit MainWidget(QObject* parent = nullptr);
  ~MainWidget();

 public slots:
  void ShowMainWidget();
  void SetWidgetGeometry(const QRect& initial_position);

 private:
  AtmMainWidget* atm_main_widget_ = nullptr;
  QRect* main_widget_position_ = nullptr;
};

#endif  // MAIN_WIDGET_H
