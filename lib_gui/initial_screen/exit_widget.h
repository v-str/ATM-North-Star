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

  void SetConnections();

 public slots:
  void Show();

 private:
  void SetInitialProperties();

  Ui::ExitWidget* ui = nullptr;
};

#endif  // EXIT_WIDGET_H
