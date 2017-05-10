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

  void SetWidgetColor(const QString& main_color = "black",
                      const QString& secondary_color = "grey",
                      const QString& additional_color = "blue");
  void SetBackgroundImage(
      const QString& background_image = ":/images/north_star_background.jpg");
  void SetBackgroundColor(
      const QString& background_color = "rgb(115, 210, 22)");

 public slots:
  void Show();

 private:
  void SetConnections();
  void SetInitialProperties();

  Ui::ExitWidget* ui = nullptr;
};

#endif  // EXIT_WIDGET_H
