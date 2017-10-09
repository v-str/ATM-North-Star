#ifndef MAIN_WIDGET_PRESENTER_H
#define MAIN_WIDGET_PRESENTER_H

#include <QObject>

class MainWidgetPresenter : public QObject {
  Q_OBJECT
 public:
  explicit MainWidgetPresenter(QObject* parent = nullptr);
  ~MainWidgetPresenter();
};

#endif  // MAIN_WIDGET_PRESENTER_H
