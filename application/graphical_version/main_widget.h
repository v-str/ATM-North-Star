#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QObject>

class AtmMainWidget;
class QRect;

namespace gui {

class MainWidget : public QObject {
  Q_OBJECT
 public:
  explicit MainWidget(QObject* parent = nullptr);
  ~MainWidget();

  void SetMainWidgetAppearance();

 public slots:
  void ShowMainWidget();
  void SetInitialPosition(const QRect& initial_position);

 private:
  AtmMainWidget* main_widget_ = nullptr;
  QRect* initial_main_widget_position_ = nullptr;
};
}

#endif  // MAIN_WIDGET_H
