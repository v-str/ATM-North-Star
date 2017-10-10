#ifndef MAIN_WIDGET_PRESENTER_H
#define MAIN_WIDGET_PRESENTER_H

#include <QObject>
#include <QRect>

class AtmMainWidget;

class MainWidgetPresenter : public QObject {
  Q_OBJECT
 public:
  explicit MainWidgetPresenter(QObject* parent = nullptr);
  ~MainWidgetPresenter();

 public slots:
  void ShowMainWidget();
  void SetWidgetGeometry(const QRect& initial_position);
  void SetMaximized(bool is_maximized);

 signals:

 private:
  AtmMainWidget* atm_main_widget_ = nullptr;

  QRect main_widget_position_;

  bool is_maximized_ = false;
};

#endif  // MAIN_WIDGET_PRESENTER_H
