#ifndef EXIT_WIDGET_H
#define EXIT_WIDGET_H

#include <QWidget>

class QTimer;
class QString;

namespace Ui {
class ExitWidget;
}

class ExitWidget : public QWidget {
  Q_OBJECT

 public:
  explicit ExitWidget(QWidget* parent = nullptr);
  ~ExitWidget();

  void SetWidgetColor(const QString& main_color,
                      const QString& secondary_color,
                      const QString& additional_color);

 public slots:
  void Show();

 private:
  void SetConnections();
  void SetInitialProperties();

  Ui::ExitWidget* ui = nullptr;
};

#endif  // EXIT_WIDGET_H
