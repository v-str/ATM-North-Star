#ifndef EXIT_WIDGET_H
#define EXIT_WIDGET_H

#include <QWidget>

#include <text_animation.h>

class QTimer;

namespace Ui {
class ExitWidget;
}

class ExitWidget : public QWidget {
  Q_OBJECT

 public:
  explicit ExitWidget(QWidget* parent = nullptr);
  ~ExitWidget();

 signals:
  void EndText();

 public slots:
  void AnimateText();

 private:
  void SetInitialProperties();

  Ui::ExitWidget* ui = nullptr;
  QTimer* timer_ = nullptr;
  TextAnimation* text_animation_ = nullptr;
};

#endif  // EXIT_WIDGET_H
