#ifndef EXIT_DIALOG_H
#define EXIT_DIALOG_H

#include <QDialog>

#include <widget_color_designer.h>

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

  void SetExitDialogAppearance(const QString& main_color,
                               const QString& secondary_color,
                               const QString& additional_color);
  void SetBackgroundColor(
      const QString& background_color = "rgb(115, 210, 22)");
  void ShowWidgetOnCenterAt(const QRect& widget_geometry);

 private:
  void SetConnections();
  void SetInitialProperties();
  void PaintWidgets();

  Ui::ExitDialog* ui = nullptr;

  WidgetColorDesigner color_designer_;
};

#endif  // EXIT_DIALOG_H
