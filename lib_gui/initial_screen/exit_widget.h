#ifndef EXIT_WIDGET_H
#define EXIT_WIDGET_H

#include <QWidget>

class QTimer;

namespace Ui {
class ExitWidget;
}

class ExitWidget : public QWidget {
  Q_OBJECT

 public:
  explicit ExitWidget(QWidget* parent = nullptr);
  ~ExitWidget();

 private:
  void SetInitialProperties();

  Ui::ExitWidget* ui = nullptr;
  QTimer* timer_ = nullptr;
};

#endif  // EXIT_WIDGET_H
