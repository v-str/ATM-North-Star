#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QObject>

class AtmMainWidget;

namespace gui {

class MainWidget : public QObject {
  Q_OBJECT
 public:
  explicit MainWidget(QObject* parent = nullptr);
  ~MainWidget();

 signals:

 public slots:
  void ShowMainWidget();

 private:
  AtmMainWidget* main_widget_ = nullptr;
};
}

#endif  // MAIN_WIDGET_H
