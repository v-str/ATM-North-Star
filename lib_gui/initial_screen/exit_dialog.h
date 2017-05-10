#ifndef EXIT_DIALOG_H
#define EXIT_DIALOG_H

#include <QDialog>

class QTimer;
class QString;
class QRect;

namespace Ui {
class ExitDialog;
}

class ExitDialog : public QDialog {
  Q_OBJECT

 public:
  explicit ExitDialog(QWidget* parent = nullptr);
  ~ExitDialog();

  void SetWidgetColor(const QString& main_color = "black",
                      const QString& secondary_color = "grey",
                      const QString& additional_color = "blue");
  void SetBackgroundImage(
      const QString& background_image = ":/images/north_star_background.jpg");
  void SetBackgroundColor(
      const QString& background_color = "rgb(115, 210, 22)");
  void ShowOnCenterAt(const QRect& center_widget);

 private:
  void SetConnections();
  void SetInitialProperties();

  Ui::ExitDialog* ui = nullptr;
};

#endif  // EXIT_DIALOG_H
