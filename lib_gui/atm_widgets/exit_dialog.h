#ifndef EXIT_DIALOG_H
#define EXIT_DIALOG_H

#include <QDialog>

#include <atm_color_designer.h>

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

  void SetExitDialogAppearance();
  void SetBackgroundColor(const QString& background_color);
  void ShowWidgetOnCenterAt(const QRect& widget_geometry);

 private:
  void SetConnections();
  void SetInitialProperties();
  void PaintWidgets();

  Ui::ExitDialog* ui = nullptr;

  AtmColorDesigner color_designer_;
};

#endif  // EXIT_DIALOG_H
